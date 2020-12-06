#include <Servo.h>
Servo servo3;
Servo servo5;
const int pwmPin3 = 3; // Servo3 pin3 PWM
const int pwmPin5 = 5; // Servo5 pin5 PWM

char caracter;
String palabra;
String angulo_1;
String angulo_2;

int k1;

void setup() {
Serial.begin(9600);
pinMode (pwmPin3, OUTPUT); 
pinMode (pwmPin5, OUTPUT);
servo3.attach(pwmPin3);
servo5.attach(pwmPin5);
}

void loop() {

  if(Serial.available())
  {
    caracter = Serial.read();  
    palabra = palabra + caracter; 

if (caracter == '*') {
      Serial.println(palabra);
      palabra = palabra.substring(0, palabra.length() - 1); // Delete last char *
      k1 = palabra.indexOf(',');
      angulo_1 = palabra.substring(0, k1);
      angulo_2 = palabra.substring(k1+1, -1);

      servo3.write(angulo_1.toInt());
      servo5.write(angulo_2.toInt());
      palabra = "";   
  }
      }
} // => Fin Loop
