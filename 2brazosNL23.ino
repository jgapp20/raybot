
#include <VarSpeedServo.h> 
#include "DHT.h"


#define DHTPIN 3
#define DHTPIN2 2
#define DHTTYPE DHT11


 
VarSpeedServo servo8;  // create servo object to control a servo 
                         // a maximum of eight servo objects can be created 
VarSpeedServo servo9;
VarSpeedServo servo10;
VarSpeedServo servo11;

const int DHTPin = 3;     // what digital pin were connected to
const int DHTPin2 = 2;   

DHT dht(DHTPin, DHTTYPE);
DHT dht2(DHTPin2, DHTTYPE);


const int servoPin8 = 8; // the digital pin used for the first servo
const int servoPin9 = 9; // the digital pin used for the second servo
const int servoPin10 = 10; 
const int servoPin11 = 11;



int pos = 0;    // posicion del servo
int contador=0;

void setup() {
  servo10.attach(10);  // servo al pin digital 8 s3
  servo11.attach(11);  // s4  vincula el servo al pin digital 9
  servo8.attach(8);  // s1  vincula el servo al pin digital 10  
  servo9.attach(9); 

  Serial.begin(9600); //Inicializo el puerto serial a 9600 baudios
  dht.begin();
  dht2.begin();

}

void loop () {
  if (Serial.available()) { //Si está disponible
    char c = Serial.read(); //Guardamos la lectura en una variable char
    if (c == '1') { 
       servo9.write(10,30,false);   //fuera        //  move the servo to 180, slow speed, run in background
    } else if (c == '2') {     
      servo9.write(150,30,false); // dentro
    } else if (c == '3') {     
      servo8.write(160,30,false); // arriba  
    } else if (c == '4') {     
      servo8.write(10,30,false); // abajo          
    } else if (c == '5') {     
      servo11.write(160,30,false); //    dentro   
    } else if (c == '6') {     
      servo11.write(10,30,false); //    fuera   
    } else if (c == '7') {     
      servo10.write(10,30,false); //    Arriba
    } else if (c == '8') {     
      servo10.write(160,30,false); //    Abajo 

      
    } else if (c == 'a') { 
      
      servo8.write(160,30,false); //arriba
      servo9.write(10,30,false); //fuera
      delay (1700);
      servo8.write(10,30,true); //abajo
      servo9.write(120,30,false); //semi dentro  
      delay (1500);
      servo8.write(90,30,false); //centro   
    } else if (c == 'b') { 
      servo10.write(10,30,false); //arriba
      servo11.write(10,30,false); //fuera 
      delay (1800);
      servo10.write(160,30,false); //abajo
      servo11.write(160,30,false); //dentro
      delay (1800);
      servo10.write(90,30,false); //centro
      servo11.write(90,30,false); //centro  

                
    } else if (c == '0') { 
      servo8.write(160,30,false); //arriba
      servo9.write(10,30,false); //fuera
      servo10.write(10,30,false); //arriba
      servo11.write(10,30,false); //fuera 
      
      delay (1800);
      servo8.write(10,30,false); //abajo
      servo9.write(160,30,false); //dentro 
      servo10.write(160,30,false); //abajo
      servo11.write(160,30,false); //dentro      
      delay (1800);
      servo9.write(90,30,false); //centro       
      servo8.write(90,30,false); //centro  
      servo10.write(90,30,false); //centro
      servo11.write(90,30,false); //centro 
      
   } else if (c == '9') { 
      servo8.write(160,30,true); //arriba
      servo9.write(10,30,true); //fuera
      servo10.write(10,30,true); //arriba
      servo11.write(10,30,true); //fuera 
      
      delay (1800);
      servo8.write(10,30,true); //abajo
      servo9.write(160,30,true); //dentro 
      servo10.write(160,30,true); //abajo
      servo11.write(160,30,true); //dentro      
      delay (1800);
      servo9.write(90,30,true); //centro       
      servo8.write(90,30,true); //centro  
      servo10.write(90,30,true); //centro
      servo11.write(90,30,true); //centro 
      
          
    } else if (c == 'y') { 
       servo9.write(180,57,false);  
       servo10.write(0,57,false);  
       servo11.write(180,57,false);  
       servo8.write(180,57,false);  
       delay (600);
       servo9.write(0,57,true);  
       servo10.write(170,57,true);  
       servo11.write(0,57,true);  
       servo8.write(10,57,true);         
       delay (600);
       servo9.write(0,57,false);  
       servo10.write(170,57,false);  
       servo11.write(0,57,false);  
       servo8.write(10,57,false);         
    }else if (c == 'x') { 
      servo9.write(90,127,false);        // move the servo to 90, fast speed, run background
      servo11.write(90,127,false); 
      servo9.write(90,127,true);         // move the servo to 90, fast speed, wait until done
    
      servo8.write(90,30,false);           // move the servo to 90, slow speed, run in background
      servo10.write(90,30,true);            // move the servo to 90, slow speed, wait until done
    }    
  }
  // Wait a few seconds between measurements.
  delay(500);

  // Reading temperature or humidity takes about 250 milliseconds!
  float h = dht.readHumidity() / 1;
  float t = dht.readTemperature() / 1;
  float h2 = dht2.readHumidity() / 1;
  float t2 = dht2.readTemperature() / 1;
  
  if (isnan(h) || isnan(h2)) {
    //Serial.println("No hay sensor!");
    //return;
  }


  Serial.print(h);
  Serial.print(" | ");
  Serial.print(h2);
  Serial.print("H ");
  
  Serial.print(t);
  Serial.print(" | ");
  Serial.print(t2);
  Serial.print("C ");
  delay (200);
  Serial.println ();

}
