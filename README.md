
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
7. [Autores](#Autores)

>Nota


## Resumen
El proyecto Rowing Machine consiste en la adaptación e instrumentación de la maquina de remo Concept2, con el objetivo de implementarla como un dispositivo de rehabilitación para pacientes con lesión medular menor a T7 mediante la asistencia controlada del movimiento de flexión y extensión propio del ejercicio de remo. 
Como respuesta a se realiza el diseño de un mecanismo de movimiento lineal capaz de desplazar al paciente según los perfiles de desplazamiento propios del ejercicio, mediante la implementación de un sistema de poleas que transmite la potencia suministrada por un motor DC controlado desde una interfaz web por medio de la tarjeta de desarrollo ESP32

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
1. **ACOPLE SILLA RIEL**
El ensamble de este subsistema se realiza sobre la viga de la máquina Concept2, ubicando las platinas en los laterales del riel y los rodillos en la superficie superior e inferior del mismo, el detalle de este ensamble se encuentra contenido en el plano #70 
<p align="center">
    <img src="https://user-images.githubusercontent.com/53317895/226142626-c23eb29f-8360-418d-907a-f1ed1884f298.png" alt="tool" width="500" /> <br/>
 </p>

2. **SILLA ERGONÓMICA**
<p align="center">
    <img src="https://user-images.githubusercontent.com/53317895/226143649-2eb1c5f1-3ea4-46a5-a213-92f141e8ada4.png" alt="tool" width="500" /> <br/>
 </p> 
 
 3. **MECANISMO DE MOVIMIENTO LINEAL**
 
<p align="center">
    <img src="https://user-images.githubusercontent.com/53317895/226144620-159d650f-b8ae-42fa-ac9b-2f3dde2aad7d.png" alt="tool" width="500" /> <br/>
 </p> 
 
 4. **SUJECIÓN MIEMBROS INFERIORES**
 <p align="center">
    <img src="https://user-images.githubusercontent.com/53317895/226144331-fddea5c7-6052-4350-88ae-a2378b8543bf.png" alt="tool" width="500" /> <br/>
 </p> 
 
 5. **ENSAMBLE GENERAL**
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
    <img src="https://user-images.githubusercontent.com/63918023/226268678-e2a00aa6-794b-47b3-aa03-f7d0e471db9c.png" alt="tool" width="500" /> <br/>
 </p>

El microcontrolador ESP32 tiene un módulo Wi-Fi que permite que el sistema se pueda conectar a una red local; además, al contar con suficiente memoria, este dispositivo puede ser utilizado como servidor para soportar una página web simple. Los archivos necesarios para esta página web tienen que ser guardados en una carpeta llamada data. Una vez se conecta el microcontrolador al Wi-Fi, se puede acceder a estos archivos a través de la dirección IP asiganada a este dispositivo, desde cualquier otro celular o computador conectado a la misma red local. Para hacer el intercambio de información entre la página web corriendo en los dispositivos conectados y el programa de control de arduino se hace el uso de peticiones Http (HTTP requests) con las que se comparten los datos recogidos por los sensores y se muestran en la interfaz.

Una vez explicados los detalles técnicos de la interfaz, podemos pasar a ver su funcionamiento. Primero que todo, para asegurar que no cualquier persona pueda controlar la máquina, se cuenta con un incio de sesión con usuario y contraseña. Además de una sección de información donde se explica el objetivo de la página web.


<p align="center">
    <img src="https://user-images.githubusercontent.com/53317895/226145103-8eb52a06-be2d-4647-8012-ad020e4f36a1.png" alt="tool" width="500" /> <br/>
 </p>
 <p align="center">
    <img src="https://user-images.githubusercontent.com/53317895/226145137-32e4a9a7-c33f-4f84-a4bf-e0b509374bb6.png" alt="tool" width="500" /> <br/>
 </p>
 
<p align="center">
    <img src="https://user-images.githubusercontent.com/53317895/226145152-480f9f8f-8149-4210-8268-3ea3fefff237.png" alt="tool" width="500" /> <br/>
 </p>
 
## Sistema eléctrico 

<p align="center">
    <img src="https://user-images.githubusercontent.com/53317895/225231644-08532db2-40a7-4afc-87ba-0b8fd96cf272.png" alt="tool" width="500" /> <br/>
 </p>


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
