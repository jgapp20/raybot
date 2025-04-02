
#include <VarSpeedServo.h> 
#include "DHT.h"


#define DHTPIN 0

#define DHTTYPE DHT11


 
VarSpeedServo servo7;  // create servo object to control a servo 

const int DHTPin = 0;     // what digital pin were connected to
 

DHT dht(DHTPin, DHTTYPE);



const int servoPin7 = 7; // the digital pin used for the first servo



int pos = 0;    // posicion del servo
int contador=0;

void setup() {
  servo7.attach(7);  // servo al pin digital 8 s3
  

  Serial.begin(9600); //Inicializo el puerto serial a 9600 baudios
  dht.begin();
  

}

void loop () {
  if (Serial.available()) { //Si está disponible
    char c = Serial.read(); //Guardamos la lectura en una variable char
    if (c == '1') { 
       servo7.write(0,30,false);   //fuera        //  move the servo to 180, slow speed, run in background
       delay(3000);
       servo7.write(90,30,false);
    } else if (c == '2') {     
      servo7.write(180,30,false); // dentro
      delay(3000);
      servo7.write(90,30,false);
    
    }     
  }
  // Wait a few seconds between measurements.
  delay(500);

  // Reading temperature or humidity takes about 250 milliseconds!
  float h = dht.readHumidity() / 1;
  float t = dht.readTemperature() / 1;

  
  if (isnan(h)) {
    //Serial.println("No hay sensor!");
    //return;
  }


  Serial.print(h);
  Serial.print("H ");
  
  Serial.print(t);
  Serial.print("C ");
  delay (200);
  Serial.println ();

}
