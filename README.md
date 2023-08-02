
<h1 align="center"> Rowing Machine Project 🦾  </h1> 

En este repositorio encontrarás documentación, manuales, códigos e hipervínculos asociados al proyecto _Rowing Machine_ 2022-2

---

### Contenido
1. [Resumen](Resumen) 
2. [Unidad de almacenamiento](#Unidad-de-almacenamiento)
3. [Modelo CAD](#Modelo-CAD)
4. [Manual de ensamble](#Manual-de-ensamble )
5. [Manual de operación](#Manual-de-operación) 
6. [Sistema eléctrico](#Sistema-eléctrico)
7. [Documentación Interfaz Control](#Documentación-Interfaz-Control)
8. [Autores](#Autores)

>Nota


## Resumen
El proyecto Rowing Machine consiste en la adaptación e instrumentación de la maquina de remo Concept2, con el objetivo de implementarla como un dispositivo de rehabilitación para pacientes con lesión medular menor a T7 mediante la asistencia controlada del movimiento de flexión y extensión propio del ejercicio de remo. 
Como respuesta a se realiza el diseño de un mecanismo de movimiento lineal capaz de desplazar al paciente según los perfiles de desplazamiento propios del ejercicio, mediante la implementación de un sistema de poleas que transmite la potencia suministrada por un motor DC controlado desde una interfaz web por medio de la tarjeta de desarrollo ESP32
<p align="center">
    <img src="https://user-images.githubusercontent.com/53317895/210720098-789618ae-394b-46b5-9458-a66aac7c1bcf.png" alt="tool" width="500" /> <br/>
 </p>
 
## Unidad de almacenamiento 

A lo largo del desarrollo del proyecto se optó por almacenar los archivos relacionados al proyecto en una unidad compartida de Google Drive, los archivos fueron organizados en 14 carpetas que incluyen la documentación previa provista por los directores del proyecto, las actas, actividades y planeación que reflejan la metodología implementada en la ejecución del proyecto y archivos CAD (planos y modelos) correspondientes a la adaptación realizada. El acceso a la unidad compartida es restringido por lo cual es necesario solicitar acceso por medio de los correos electronicos de los autores adjuntos al final de este repositorio.

<p align="center">
    <img src="https://user-images.githubusercontent.com/53317895/210720098-789618ae-394b-46b5-9458-a66aac7c1bcf.png" alt="tool" width="500" /> <br/>
 </p>
 

## Modelo CAD
Se realiza un modelo CAD utilizando el sofware Autodesk Inventor en su versión 2022, este modelo se encuentra organizado en cinco carpetas correspondientes a los subsistemas que componen el diseño general 
<p align="center">
    <img src="https://user-images.githubusercontent.com/53317895/212462906-c6280e85-7df6-492d-9742-acad1538cda0.png" alt="tool" width="500" /> <br/>
 </p>

1. Mecanismo de movimiento lineal (MML)
2. Sujeción silla (SLL)
3. Acople silla riel (ASR) 
4. Sistema eléctrico y electrónico (SEL) 
5. Sujeción miembros inferiores (SMI) 

Finalmente, se realiza un ensamble general donde se integran todos los subsitemas, este archivo se encuentra como **1.GENERAL_Proyecto_ada_maq_remo.iam**
El link para acceder al modelo es el siguiente: [CAD COLABORATIVO](https://drive.google.com/drive/folders/1i63YF57rcCv_cbrC5JMalGdo3bhI2gLO?usp=share_link)


## Manual de ensamble 
El ensamble se realiza sobre la máquina de remo Concept2 Model D, por lo cual resulta necesario tener previamente ensamblada la máquina según las indicaciones del fabricante, a continuación se adjunta el hipervínculo al manual de ensamble suministrado por Concept2  [Model D Assembly Instructions](https://www.concept2.com/service/indoor-rowers/model-d/manuals-and-schematics).
Una vez se tiene la máquina correctamente ensamblada, se sugiere seguir el siguiente orden para instalar los subsistemas que componen la adaptación:
1. **ACOPLE SILLA RIEL:**
El ensamble de este subsistema se realiza sobre la viga de la máquina Concept2, ubicando las platinas en los laterales del riel y los rodillos en la superficie superior e inferior del mismo, teniendo en cuenta el contenido ensamblado con los rodillos, posterior se ajustan los ejes desde cada platina, el detalle de este ensamble se encuentra contenido en el plano #70.
<p align="center">
    <img src="https://user-images.githubusercontent.com/53317895/226142626-c23eb29f-8360-418d-907a-f1ed1884f298.png" alt="tool" width="500" /> <br/>
 </p>

2. **SILLA ERGONÓMICA:**
Se continua con el ensamble de este subsistema, realizado sobre el acople recién ajustado, ubicando la base estructural sobre esta, la cual se une a la base acolchada y al perfil estructural del espaldar, el cual también cuenta con un acolchado ajustable a la espalda.
<p align="center">
    <img src="https://user-images.githubusercontent.com/53317895/226143649-2eb1c5f1-3ea4-46a5-a213-92f141e8ada4.png" alt="tool" width="500" /> <br/>
 </p> 
 
3. **MECANISMO DE MOVIMIENTO LINEAL:**
Proceda con el ensamble del mecanismo que permite el movimiento asistido, el cual se compone del soporte, que mantendrá el motor, la transmisión y la caja eléctrica, la correa y soportes frontal y trasero del movimiento lineal; donde se obtiene el ensamble del soporte del motor con sus elementos, el cual se ajusta a la base trasera de la máquina Concept2, luego se ajustan los soportes a la viga principal, donde van en la parte inferior junto a las poleas, continuando con el ajuste de las correas de transmisión pasando por las poleas al igual que ajustándola al acople silla-riel. 
<p align="center">
    <img src="https://user-images.githubusercontent.com/53317895/226144620-159d650f-b8ae-42fa-ac9b-2f3dde2aad7d.png" alt="tool" width="500" /> <br/>
 </p> 
 
4. **SUJECIÓN MIEMBROS INFERIORES:**
De forma separada y sin depender de lo anterior, se puede realizar el ajuste del sistema de sujeción para miembros inferiores, donde primero se realiza el ensamble del subsistema para luego si ajustarlo a la máquina Concept2. El subsistema tiene el orden de ensamble de la barra más ancha a las más angosta, con el fin de introducirlos correctamente permitiendo obtener el sistema de barra telescópica, en la punta se ajustan los soportes de resina y fibra para las piernas, colocándoles la correa de seguridad. Procedemos con el ajuste del soporte en la viga secundaria, bajo el punto seguro de la manija, y a las orejas ajustamos el sistema de barras ensamblado.
 <p align="center">
    <img src="https://user-images.githubusercontent.com/53317895/226144331-fddea5c7-6052-4350-88ae-a2378b8543bf.png" alt="tool" width="500" /> <br/>
 </p> 
 
5. **ENSAMBLE GENERAL:**
Finalmente observamos el ensamble completo en el que podemos comprobar el ajuste de cada uno de los subsistemas y su lugar en la maquina Concept2, identificando su operación conjunta.
  <p align="center">
    <img src="https://user-images.githubusercontent.com/53317895/226144190-366b1945-7734-4a68-b3fc-990733a97678.png" alt="tool" width="500" /> <br/>
 </p> 

## Manual de operación 

Se verifica que el botón de emergencia se encuentre presionado y el selector se encuentre en posición de apagado (parte superior hacia el borde de la caja) 

<p align="center">
    <img src="https://user-images.githubusercontent.com/53317895/212463168-e9b1b28e-fd3f-4bfd-8c45-19a19658c492.png" alt="tool" width="500" /> <br/>
 </p>

### Operación serial (Alámbrica)

<p align="center">
    <img src="https://user-images.githubusercontent.com/53317895/226144815-ecb824c0-60b0-49fb-966c-5556b43c707c.png" alt="tool" width="200" /> <br/>
 </p>
 <p align="center">
    <img src="https://user-images.githubusercontent.com/53317895/226144921-ae219886-67c0-447e-88c4-7f54fed93108.png" alt="tool" width="200" /> <br/>
 </p>
 
<p align="center">
    <img src="https://user-images.githubusercontent.com/53317895/226144894-66bc88e6-0c67-4384-bf6f-ed41d9945920.png" alt="tool" width="500" /> <br/>
 </p>
 

 

### Operación Interfaz Web (Inalámbrica)

Para la operación de la interfaz Web se tiene el siguiente diagrama de comunicación. 

<p align="center">
    <img src="https://user-images.githubusercontent.com/63918023/226268678-e2a00aa6-794b-47b3-aa03-f7d0e471db9c.png" alt="tool" width="700" /> <br/>
 </p>

El microcontrolador ESP32 tiene un módulo Wi-Fi que permite que el sistema se pueda conectar a una red local; además, al contar con suficiente memoria, este dispositivo puede ser utilizado como servidor para soportar una página web simple. Los archivos necesarios para esta página web tienen que ser guardados en una carpeta llamada data. Una vez se conecta el microcontrolador al Wi-Fi, se puede acceder a estos archivos a través de la dirección IP asiganada a este dispositivo, desde cualquier otro celular o computador conectado a la misma red local. Para hacer el intercambio de información entre la página web corriendo en los dispositivos conectados y el programa de control de arduino se hace el uso de peticiones Http (HTTP requests) con las que se comparten los datos recogidos por los sensores y se muestran en la interfaz.

Una vez explicados los detalles técnicos de la interfaz, podemos pasar a ver su funcionamiento. Primero que todo, para asegurar que no cualquier persona pueda controlar la máquina, se cuenta con un incio de sesión con usuario y contraseña. Además de una sección de información donde se explica el objetivo de la página web.

<p align="center">
    <img src="https://user-images.githubusercontent.com/53317895/226145137-32e4a9a7-c33f-4f84-a4bf-e0b509374bb6.png" alt="tool" width="500" /> <br/>
</p>
<p align="center">
    <img src="https://user-images.githubusercontent.com/53317895/226145103-8eb52a06-be2d-4647-8012-ad020e4f36a1.png" alt="tool" width="500" /> <br/>
 </p>
 
 Luego de iniciar sesión se puede continuar a hacer el control de la máquina. En la página principal existe una barra superior desde la que se puede acceder rápidamente a los perfiles leidos por los sensores y además se puede cerrar la sesión. En la parte izquierda se cuenta con una barra de control desde la que se puede hacer la calibración de la máquina, iniciar la operación y deterla. La interfaz no va a permitir que se haga el inicio de la rutina sin que previamente se haga la calibración de la máquina. Por último, se tiene la sección de disposición de información leída: allí se encuentras los valores actuales leídos y además un record en forma de gráficas de Posición, Velocidad y Aceleración leídas desde la máquina. 
 
<p align="center">
    <img src="https://user-images.githubusercontent.com/53317895/226145152-480f9f8f-8149-4210-8268-3ea3fefff237.png" alt="tool" width="500" /> <br/>
 </p>
 
 En el [manual de operación](https://github.com/Danacruzrui/Rowing_Machine/blob/a2b3f7ed87f60954caf2f44a7c11d9946a2204fc/Manuales/Manual%20de%20Manejo%20de%20Interfaz%20Web.pdf) con la interfaz web se explica detalladamente cómo se hace la conexión a Wi-Fi de la ESP32 cómo se obtiene la dirección IP a la que se deben conectar los dispositivos desde los que se quiera controlar la máquina.
 
 ***Nota importante:***
 
 Es importante aclarar que debido a algunos problemas presentados durante la realización de las primeras pruebas de funcionamiento por parte de la interfaz Web, donde algunas veces si realizaba la conexión y podía recibir y enviar datos con la ESP32 y algunas veces no; y teniendo en cuenta que en muchos lugares de Colombia las redes no son lo suficientemente rápidas o estables como para actuar inmediatamente en la máquina; y que en este sentido se pondría en riesgo la salud del paciente; se decidió cambiar a una interfaz con comunicación serial. 
 
 De esta manera, poniendo en primer lugar la seguridad del paciente, los avances realizados con la interfaz web llegan hasta un punto donde pueden no ser compatibles con la versión final del mecanismo y sensores. En caso de que si, esta no debe ser usados en pruebas con pacientes reales. Sin embargo, los archivos respectivos a esta Interfaz se presetan aquí como información base en caso de que alguien más quiera realizar avances o nuevas implementaciones con ella. 
 
 
## Sistema eléctrico 

<p align="center">
    <img src="https://user-images.githubusercontent.com/53317895/225231644-08532db2-40a7-4afc-87ba-0b8fd96cf272.png" alt="tool" width="800" /> <br/>
 </p>
 
 Los elementos que se ven en el diagrama anterior se listan a continuación:
-	**Motor**: Este es un motor DC que funciona a 24 V de tensión, brindando una potencia nominal  de 300W y alcanza cerca de 2750 rpm (Se encuentra debajo y a un extremo de la viga sobre la que se mueve la silla)
-	**Fuente**: Se dispone de una fuente de 24V para hacer la alimentación del motor a través del driver. (Se encuentra dentro de la caja de control)
-	**Driver**: Este driver tiene referencia IBT2 y es el encargado de convertir las señales de control del microcontrolador en señales de potencia de alta corriente para hacer mover el motor. Recibe entradas entre 3.3V – 5V y las convierte en salidas desde 5,5V a 28V (Se encuentra dentro de la caja de control)
-	**Microcontrolador**: Se usó un microcontrolador ESP32 para generar las rutinas, sistemas de control y adquisición de datos. (Se encuentra dentro de la caja de control)
-	**Encoder**: El encoder usado permite la lectura de 360 pulsos por revolución. (Se encuentra dispuesto en el eje del motor)
-	**Finales de carrera**: Dos sensores que generan señales cuando la silla llega a los límites de movimiento. Se usaron sensores de campo magnético reed switch. (Se encuentran sobre la viga de movimiento de la silla)
-	**Sensor de distancia**: El sensor con referencia VL53L0X proporciona la medida de distancia de movimiento de la silla. (Está puesto en un extremo de la viga)

 

## Documentación Interfaz Control
La interfaz de control de la adaptación de la máquina de remo Concept 2, fue definida como un GUI modelada en Python usando la librería tktinker, en lo que sigue, se definirán las características que la integran con el fin de lograr un uso adecuado de esta y con ello conseguir una manipulación idónea de la máquina de remo Concept 2 adaptada. La aplicación desarrollada lleva por nombre Control Concept 2. El siguiente repositorio contiene información detallada del [Código de control e interfaz](https://github.com/javca01/Documentacion-Control-Concept-2).

## Autores
> - Brayan Stiven Acuña García (bsacunag@unal.edu.co)
> - [Javier Caicedo Pedrozo](https://github.com/jcaicedop)   (jcaicedop@unal.edu.co)
> - [Daniel Alexander Cruz Ruiz ](https://github.com/Danacruzrui) (danacruzrui@unal.edu.co) 
> - Angel Steven Forero Cuervo (asforeroc@unal.edu.co)
> - [Jhon Brandol Muñoz Romero](https://github.com/Jhonbrando)(jbmunozr@unal.edu.co)
> - [Diego Fabián Osorio Fonseca](https://github.com/dosoriof) (dosoriof@unal.edu.co)
> - [Camilo Pineda Correa](https://github.com/capinedac) (capinedac@unal.edu.co)
---
## Directores

> - Angélica Maria Ramirez Martinez
> - Angie Stephanie Vega Toro
> - Hernan David Barreto Garzón
