#include <NewPing.h>
NewPing sonar(11,12);



char dato;
boolean cambio=1;
int distancia;

void setup( ) {
  
 pinMode(2,OUTPUT);
 pinMode(4,OUTPUT);
 pinMode(8,OUTPUT);
 pinMode(9,OUTPUT);
 Serial.begin(9600);
}

void loop( ) {

  
  
   while(cambio==1){ 
    if (Serial.available() > 0) {
    dato = Serial.read();
    }
    switch (dato) {

      case ('F'): {    
           moves(1,1,255,255); 
          
           break;
      }
     
      case ('B'): {    
           moves(0,0,255,255);
          
           break;          
      }
      
      case ('G'): {       
           moves(1,1,255,100);
           
           break;
      }
      
      case ('I'): {     
           moves(1,1,100,255);
           
           break;
      }
        
      case ('L'): {     
           moves(1,1,255,0);
          
           break;
      }
      case ('R'): {     
           moves(1,1,0,255);
          
           break;
      }
      case ('H'): {       
           moves(0,0,255,100);
           
           break;
      }
      case ('J'): {     
           moves(0,0,100,255);
           
           break;          
      }
      case ('S'): {
           analogWrite(3,0);
           analogWrite(10,0);
      }
      case ('W'): {
           cambio=0;
      }
          
      
   }
   }
   while(cambio==0){
     distancia=sonar.ping_cm();
     delay(50);
     if(distancia>15){
       digitalWrite(7,0);
       moves(1,1,255,255);
     }
     if(distancia<=15){
       digitalWrite(7,1);
       moves(0,0,120,120);
       delay(50);
       moves(1,0,120,120);
     }
     dato = Serial.read();
     if(dato=='B')cambio=1;
    
   }
    
  
}

void moves(int a, int c, int v1, int v2){
   digitalWrite(2,!a);
   digitalWrite(4,a);
   digitalWrite(8,!c);
   digitalWrite(9,c);
   analogWrite(3,v1);
   analogWrite(10,v2);
}
