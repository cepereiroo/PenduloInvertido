# PenduloInvertido_Cecilia
En este repositorio se encuentra tanto la práctica 4 cómo la práctica 6 de la asignatura de Teoría de Control 

**PRÁCTICA 4 - PID en tiempo discreto** 

Esta práctica tiene como objetivo implementar una biblioteca de controladores PID en tiempo discreto para ser utilizada en un microcontrolador ESP32, con aplicación directa en el control de un péndulo invertido. Esta biblioteca será utilizada en el desarrollo del proyecto de control descrito en el capítulo 6 del guión de prácticas. 

Se desarrollarán tres variantes del controlador PID en tiempo discreto: 

- **PID** : utiliza aproximaciones hacia atrás para las derivadas y sumas acumulativas para la integral. 
- **PID como filtro IIR**: modelado mediante transformada Z, facilitando su implementación como filtro digital. 
- **PID filtro baja** : se le pone un filtro al término derivativo para evitar que el ruido o los cambios bruscos del error afecten al control. 

Cada implementación está basada en los pseudocódigos del guión.  

Esta práctica está encapsulada en la carpeta libraries donde nos encontraremos :  

**I2Cdev/** 

Contiene archivos fuente y cabeceras que permiten la comunicación mediante el protocolo I2C. Es una biblioteca comúnmente usada para facilitar la lectura y escritura con sensores como el MPU6050 

**MPU6050/** 

Incluye las definiciones y funciones específicas para el sensor MPU6050, que proporciona mediciones de aceleración y giroscopio. Esta biblioteca se apoya en I2Cdev para obtener los datos del sensor y es esencial para calcular la posición y velocidad angular del péndulo. 

**PIDController/** 

Es la biblioteca desarrollada para está práctica para implementar los tres tipos de controladores PID discretos: 

- PID directo 
- PID como filtro IIR 
- PID filtro pasa ba 

Dentro de cada carpeta estarán los archivos .h y .cpp con la implementación de las clases PID 

Se añadirá además una carpeta examples que contendrá tres ejemplos simples que muestran cómo usar cada una de las variantes del controlador PID implementadas. 

**CodigoCompletoPendulo.ino** 

Este es el sketch código principal de Arduino que integra las bibliotecas anteriores. Aquí se encuentra el código de control que: 

- Lee el ángulo del péndulo usando el MPU6050 
- Calcula la señal de control con el PID 
- Aplica la corrección al actuador 
- Permite probar y comparar las distintas variantes del controlador PID 
