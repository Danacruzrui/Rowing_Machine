#include <Arduino.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <Arduino_JSON.h>
#include "SPIFFS.h"

// Sensor libraries
#include "VL53L0X.h"
#include "Wire.h"

// Conexiones ESP32
// VCC-->3,3V
// SCL-->22
// SDA-->21
// GN2-->GND
// XSH-->3,3V



/*  Configuración de la conexión Wi-Fi

En las líneas de código a continuación:
1. Reemplace el valor de la variable ssid con el nombre de su red
2. Reemplace el valor de la variable password con la contraseña de la red*/

const char* ssid = "LabLog";
const char* password = "17113467";

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

// Create an Event Source on /events
AsyncEventSource events("/events");

// Json Variable to Hold Sensor Readings
JSONVar readings;

// Timer variables
unsigned long lastTime = 0;
unsigned long valuesDelay = 50;
unsigned long gyroDelay = 10;
unsigned long temperatureDelay = 1000;
unsigned long accelerometerDelay = 200;
unsigned long initTime = 0;

// Create a sensor object - sensor distancia
VL53L0X sensor;
int medida = 0;

const int  RPWM_Output = 2;
const int  LPWM_Output = 4;
const int in1_negro=15;
const int in2_verde=23;
bool pulsacion1 = false;
bool pulsacion2 = false;
bool flag_detect_interrupt = false;
bool flag_ccw = false;
bool flag_cw = false;
bool flag_exit_ccw = false;
bool flag_exit_cw = false;
bool flag_calibracion = false;
bool flag_begin_move = false;
bool flag_home_negro = false;

const int frecuencia = 15000;
const int canal = 1;
const int resolucion = 8;


// Datos Encoder
const int channelPinA = 18; //original 21
const int channelPinB = 19; //original 22
const int timeThreshold = 1;//Valor más cercano para los 180 pulsos en media vuelta
long timeCounter = 0;
const int maxSteps = 360; //360 pulsos por revolución
volatile int ISRCounter = 0;
int counter = 0;
int counter_old = 0;
float resolution = 360.0;
float rpm = 0.0;
unsigned long timeold;
float dt=0.0;
bool IsCW = true;


int Vpwm=0;

#define LONG_RANGE

//----------------------

// Almacenamiento del valor de puerto (Rango de 0-4095)
int potValor = 0;
//
int Velocidad[ ] = {0,0,0,1,1,2,3,3,4,5,6,7,9,10,11,13,14,16,18,20,21,23,25,27,29,31,34,36,38,40,43,45,47,50,52,54,57,59,61,63,66,68,70,72,74,76,78,80,82,84,86,88,89,91,92,94,95,96,98,99,100,100,101,102,102,103,103,104,104,104,104,104,103,103,102,102,101,100,100,99,98,96,95,94,92,91,89,88,86,84,82,80,78,76,74,72,70,68,66,63,61,59,57,54,52,50,47,45,43,40,38,36,34,31,29,27,25,23,21,20,18,16,14,13,11,10,9,7,6,5,4,3,3,2,1,1,0,0,0,0,0,0,-1,-1,-2,-3,-3,-4,-5,-6,-7,-9,-10,-11,-13,-14,-16,-18,-20,-21,-23,-25,-27,-29,-31,-34,-36,-38,-40,-43,-45,-47,-50,-52,-54,-57,-59,-61,-63,-66,-68,-70,-72,-74,-76,-78,-80,-82,-84,-86,-88,-89,-91,-92,-94,-95,-96,-98,-99,-100,-100,-101,-102,-102,-103,-103,-104,-104,-104,-104,-104,-103,-103,-102,-102,-101,-100,-100,-99,-98,-96,-95,-94,-92,-91,-89,-88,-86,-84,-82,-80,-78,-76,-74,-72,-70,-68,-66,-63,-61,-59,-57,-54,-52,-50,-47,-45,-43,-40,-38,-36,-34,-31,-29,-27,-25,-23,-21,-20,-18,-16,-14,-13,-11,-10,-9,-7,-6,-5,-4,-3,-3,-2,-1,-1,0,0,0};



//Application variables
float currTime;
bool start = false;
bool calibrated = false;


//FUNCIONES COMUNICACIÓN CON PAGINA WEB

void initSPIFFS() {
  if (!SPIFFS.begin()) {
    Serial.println("An error has occurred while mounting SPIFFS");
  }
  Serial.println("SPIFFS mounted successfully");
}

// Initialize WiFi
void initWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");
  Serial.print("Connecting to WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("");
  Serial.println(WiFi.localIP());
}

String getValues(){

  medida = sensor.readRangeSingleMillimeters()/10.0;
  Serial.print("cm: ");
  Serial.print(medida);
  if (sensor.timeoutOccurred()) { Serial.print(" TIMEOUT"); medida = -1; }
  Serial.println();
  
  readings["accX"] = String(0);
  readings["velX"] = String(0);
  readings["posX"] = String(medida);

  currTime = (millis()-initTime)/1000;
  readings["time"] = String(currTime);
  
  String accString = JSON.stringify (readings);
  return accString;
}

void sendMessage(String message){
  readings["message"] = message;
  String accString = JSON.stringify (readings);
  events.send(accString.c_str(),"message",millis());
}

void sendData(float pos, float vel, float acel){
  readings["accX"] = String(acel);
  readings["velX"] = String(vel);
  readings["posX"] = String(pos);
  String accString = JSON.stringify (readings);
  events.send(accString.c_str(),"readings",millis());
}

// FUNCIONES ENCODER

void doEncodeA()
{
   if (millis() > timeCounter + timeThreshold){
      if (digitalRead(channelPinA) == digitalRead(channelPinB)){
         IsCW = true;
         ISRCounter++;
      }else{
         IsCW = false;
         ISRCounter--;
      }
      timeCounter = millis();
   }
}


void doEncodeB(){
   if (millis() > timeCounter + timeThreshold){
      if (digitalRead(channelPinA) != digitalRead(channelPinB)){
        ISRCounter++;
      }else{
         IsCW = false;
         ISRCounter--;
      }
      timeCounter = millis();
   }
}

float lectura_encoder(){
  float lect_enc = 0.0;
  if (counter != ISRCounter){
        counter_old=counter;
        counter = ISRCounter;
        dt=float(millis()-timeold);
        rpm = float((abs(counter-counter_old)/dt)*(60000.0/resolution)); //RPM
    }
    timeold = millis();
    lect_enc = rpm;
    return lect_enc;
}

int lectura_distancia(){
  int lect=0;
  lect=sensor.readRangeSingleMillimeters()/10.0;  
  if (sensor.timeoutOccurred()) { Serial.print("-1"); } //imprime -1 si no hay lectura.
  return lect;
}

// FUNCIONES CALIBRACIÓN

void rutina_parada_cw(){
  detachInterrupt(digitalPinToInterrupt(in1_negro));//Desactivamos la detección de interrupciones por el final de carrera cw.
  int Vpwm =0;
  flag_detect_interrupt = true;
  flag_cw = true;
  Serial.println("Inicio de rutina de detención extremo derecho.");
    ledcWrite(0, 0);
    ledcWrite(1, 0);
    /////////Medida del sensor///////////////
    medida=lectura_distancia();
    ////////////////////////////////////////
    ////////Lectura Encoder /////////////////
    rpm=lectura_encoder();
    sendData(float(medida),rpm,0);
    Serial.print("Pos: ");
    Serial.print(medida);
    Serial.print(", Vel: ");
    Serial.println(rpm);
  /////////////////////////////////////////
  //}
  Serial.println("Fin de rutina de parada_cw");
  flag_exit_cw = true;
}

void rutina_parada_ccw(){
  detachInterrupt(digitalPinToInterrupt(in2_verde));//Desactivamos la detección de interrupciones por el final de carrera cw.
  int Vpwm =0;
  flag_detect_interrupt = true;
  flag_ccw = true;
  Serial.println("Inicio de rutina de detención extremo izquierdo.");  
    ledcWrite(0, 0);
    ledcWrite(1, 0);
    /////////Medida del sensor///////////////
    medida=lectura_distancia();
    ////////////////////////////////////////
    ////////Lectura Encoder /////////////////
    rpm=lectura_encoder();
    sendData(float(medida),rpm,0);
  /////////////////////////////////////////
  //}
  Serial.println("Fin de rutina de parada_ccw");
  flag_exit_ccw = true;
}

//Lleva la silla hasta la mitad de la trayectoria, el cual es el punto de partida para todos los casos.
void rutina_home(){
  //Estimar cuál debe ser el perfil para llevar la silla a la posición media.
  detachInterrupt(digitalPinToInterrupt(in1_negro)); //Desactivamos la detección de interrupciones por el final de carrera negro.
  detachInterrupt(digitalPinToInterrupt(in2_verde)); //Desactivamos la detección de interrupciones por el final de carrera verde.
    int Vpwm =0;
  Serial.println("Llevando la Silla a Home");
  // desde extremos izquierdo

  if (flag_ccw == true){  //Rutina para ir a home desde el extremo izquierdo.
    Serial.println("Rutina para ir a home desde el extremo izquierdo."); 
    // Se lleva la silla a Home a velocidad constante.
      //Detenemos el motor.
        ledcWrite(0, 0);
        ledcWrite(1, 0); 
        delay(2000);
      while(digitalRead(in1_negro) == LOW && flag_home_negro == false){
        ledcWrite(0, 0);
        ledcWrite(1, 60); 
        Serial.println("60");//Corregido rutina de Home según experiencia.
        /////////Medida del sensor///////////////
        medida=lectura_distancia();
        ////////////////////////////////////////
        ////////Lectura Encoder /////////////////
        rpm=lectura_encoder();
        sendData(float(medida),rpm,0);
      /////////////////////////////////////////
      }
      flag_home_negro = true;
      //Detenemos el motor.
        ledcWrite(0, 0);
        ledcWrite(1, 0); 
      Serial.println("Posición de home alcanzada");
      delay(2000);
      flag_ccw = false;
  }else if (flag_cw == true){ //Rutina para ir a home desde el extremo derecho.
    Serial.println("Rutina para ir a home desde el extremo derecho"); 
      //Detenemos el motor.
        ledcWrite(0, 0);
        ledcWrite(1, 0); 
      Serial.println("Sistema en posición de home");  
      Serial.println("Posición de home alcanzada");
      /////////Medida del sensor///////////////
    medida=lectura_distancia();
    ////////////////////////////////////////
    ////////Lectura Encoder /////////////////
    rpm=lectura_encoder();
    sendData(float(medida),rpm,0);
  /////////////////////////////////////////
      delay(2000);
    flag_cw = false;
  }
}

void calibrate(){
  //inicio del programa
  delay(5000);
  Serial.println("Iniciando Proceso de calibración...., espere.");
  delay(2000);
  Serial.println("Iniciamos.");
  
  while(digitalRead(in2_verde) == LOW){
    //Calibrar posición del motor
    ledcWrite(0, 60);
    ledcWrite(1, 0); 
    Serial.println("60");
    /////////Medida del sensor///////////////
    medida=lectura_distancia();
    ////////Lectura Encoder /////////////////
    rpm=lectura_encoder();
    sendData(float(medida),rpm,0);
  }
  //parar motor
  ledcWrite(0, 0);
  ledcWrite(1, 0);
  Serial.println("Detenido en extremo izquierdo..., espere.");
  delay(3000);
  Serial.println("Desplazando al extremo derecho.");
  //Ir a posición intermedia
  Serial.println("Midiendo distancia.");
  //Hacer rutina para medir la distancia entre ambos extremos.
  while(digitalRead(in1_negro) == LOW){
    ledcWrite(0, 0);
    ledcWrite(1, 60);
    Serial.println("60");
    /////////Medida del sensor///////////////
    medida=lectura_distancia();
    ////////Lectura Encoder /////////////////
    rpm=lectura_encoder();
    sendData(float(medida),rpm,0);
  }
  //parar motor
  ledcWrite(0, 0);
  ledcWrite(1, 0); 
  Serial.println("Detenido en extremo derecho..., espere.");
  delay(2000);
   
  flag_calibracion = true;
  Serial.println("Fin del proceso de calibración");
  delay(3000);
   
}

// RUTINA

void rutina_movimiento(){
  if (flag_begin_move == false){
    Serial.println("Iniciando rutina de movimiento..., espere");
    delay(2000);
    Serial.println("Comenzamos");
    delay(1000);  
  }
  flag_begin_move = true;
  int Vpwm =0;
  for (int i=0;i<278;i++){
   //Giro a la derecha
    if (Velocidad[i]>=0){
      Vpwm = Velocidad[i];      
      ledcWrite(0, Vpwm);
      ledcWrite(1, 0);
     }else{
      Vpwm = -Velocidad[i];
      ledcWrite(0, 0);     
      ledcWrite(1, Vpwm);
     }
   //Análisis de la gráfica de Velocidad   
  Serial.println(Velocidad[i]); 
    delay(10); //Se llevó a 20 para que el piñón alcance a dar las tres vueltas.  
    /////////Medida del sensor///////////////
    medida=lectura_distancia();
    ////////////////////////////////////////
    ////////Lectura Encoder /////////////////
    rpm=lectura_encoder();
    sendData(float(medida),rpm,0);
  /////////////////////////////////////////
    if (flag_exit_ccw == true || flag_exit_cw == true) { //impide la reanudación de la rutina de movimiento una vez finalizan las interrupciones.
      break;
    }
  }   
}

void setup() {
  Serial.begin(115200);
  Wire.begin();
  initWiFi();
  initSPIFFS();

  // Sensor config
//  sensor.init();
//  sensor.setTimeout(4); //Original 500
//
//   #if defined LONG_RANGE
//// lower the return signal rate limit (default is 0.25 MCPS)
//  sensor.setSignalRateLimit(0.1);
//// increase laser pulse periods (defaults are 14 and 10 PCLKs)
//  sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, 18);
//  sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, 14);
//  #endif

  
  // reduce timing budget to 20 ms (default is about 33 ms)
  sensor.setMeasurementTimingBudget(20000); //20 ms de tiempo de sensado.


  //ENCODER Y FINALES DE CARRERA
  
  pinMode(RPWM_Output,OUTPUT);
  pinMode(LPWM_Output,OUTPUT);
  pinMode(in1_negro, INPUT);    
  pinMode(in2_verde, INPUT);
  
  ledcSetup(0, frecuencia, resolucion);
  ledcAttachPin( RPWM_Output,0);
 
  ledcSetup(1,frecuencia, resolucion);
  ledcAttachPin(LPWM_Output,1);
  
  //Configuración Encoder
  pinMode(channelPinA, INPUT_PULLUP);
  pinMode(channelPinB, INPUT_PULLUP);
  ///////////////////////////////////////

  //Interrupciones para el encoder.
  attachInterrupt(digitalPinToInterrupt(channelPinA), doEncodeA, CHANGE);
  attachInterrupt(digitalPinToInterrupt(channelPinB), doEncodeB, CHANGE);
  /////////////////

  //Uso de interrupciones para detectar los finales de carrera.
  attachInterrupt(digitalPinToInterrupt(in1_negro), rutina_parada_cw, CHANGE);
  attachInterrupt(digitalPinToInterrupt(in2_verde), rutina_parada_ccw, CHANGE);
  ////////////////

  //---------------



  // Handle Web Server
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/index.html", "text/html");
  });

  server.serveStatic("/", SPIFFS, "/");

  server.on("/start", HTTP_GET, [](AsyncWebServerRequest *request){
    if(calibrated){
      start = 1;
      initTime = millis();
    }else{
      sendMessage("noCalibrated");
    }
    
    request->send(200, "text/plain", "OK");
  });

  server.on("/stop", HTTP_GET, [](AsyncWebServerRequest *request){
    start = 0;
    request->send(200, "text/plain", "OK");
  });

  server.on("/calibrate", HTTP_GET, [](AsyncWebServerRequest *request){
    if(start){
      sendMessage("started");
    }else{
      calibrate();
      calibrated = true;
    }
    
    request->send(200, "text/plain", "OK");
  });

  // Handle Web Server Events
  events.onConnect([](AsyncEventSourceClient *client){
    if(client->lastId()){
      Serial.printf("Client reconnected! Last message ID that it got is: %u\n", client->lastId());
    }
    // send event with message "hello!", id current millis
    // and set reconnect delay to 1 second
    client->send("hello!", NULL, millis(), 10000);
  });
  server.addHandler(&events);

  server.begin();
}



void loop() {

  // Control de motor
  if(start){
    if (flag_detect_interrupt == false && flag_calibracion == true){
      rutina_movimiento();
    }
  }

  if(flag_ccw == true || flag_cw == true ){
    rutina_home();
  }
  /////////Medida del sensor///////////////
    medida=lectura_distancia();
    ////////////////////////////////////////
  ////////Lectura Encoder /////////////////
    rpm=lectura_encoder();
  /////////////////////////////////////////
  sendData(float(medida),rpm,0);
 
}
