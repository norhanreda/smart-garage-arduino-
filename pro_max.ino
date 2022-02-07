#define a 10
#define b 2
#define c 3
#define d 4
#define e 5
#define f 6
#define g 7
#define sensEnter 0
#define sensLeave 8
#include<Servo.h>
Servo myserv; 
int enter=1; // enter the garage
int leave=1; //leave the garage
int count=5;


/////////////////////////
//LDR Part
#define led1 11
#define led2 12
#define led3 13
#define sensor A0 // LDR sensor
int reading;

void setup() {
  pinMode(sensEnter,INPUT);
  pinMode(sensLeave,INPUT);
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(e,OUTPUT);
  pinMode(f,OUTPUT);
  pinMode(g,OUTPUT);
  myserv.attach(9);
  myserv.write(0);
  /////
   pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(sensor,INPUT);
  Serial.begin(9600);
  /////
  // put your setup code here, to run once:

}

void loop() {
  //ldr sensor
  //////////////////////
   reading=analogRead(sensor);
  if(reading>=300)
  {
  digitalWrite(led1,HIGH);
   digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
  }
  else if(reading<300)
  {
  digitalWrite(led1,LOW);
   digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
  }
 
  ///////////////////////
  enter=digitalRead(0);
  delay(50);
  leave=digitalRead(8);
  delay(50);
  if(enter==0 && count>0 )
  {
    
  for(int y=0;y<=90;y++)
  {
    //ldr sensor
    ///////////////////
     reading=analogRead(sensor);
  if(reading>=300)
  {
  digitalWrite(led1,HIGH);
   digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
  }
  else if(reading<300)
  {
  digitalWrite(led1,LOW);
   digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
  }
  
  ////////////////
  myserv.write(y);
  delay(20);
  
  }
  int leave2=digitalRead(sensLeave);
   while ( leave2 ==1)
  {
    
    leave2=digitalRead(sensLeave);
    //ldr sensor
    ////////////////
     reading=analogRead(sensor);
  if(reading>=300)
  {
  digitalWrite(led1,HIGH);
   digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
  }
  else if(reading<300)
  {
  digitalWrite(led1,LOW);
   digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
  }
  //////////////////
    }

  count--;
   for(int y=90;y>=0;y--)
  {
     reading=analogRead(sensor);
  if(reading>=300)
  {
  digitalWrite(led1,HIGH);
   digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
  }
  else if(reading<300)
  {
  digitalWrite(led1,LOW);
   digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
  }
  Serial.println(reading);
  myserv.write(y);
  delay(20);
  }
  

  
  }
  if(leave==0)
  {
     for(int y=0;y<=90;y++)
     {
        reading=analogRead(sensor);
  if(reading>=300)
  {
  digitalWrite(led1,HIGH);
   digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
  }
  else if(reading<300)
  {
  digitalWrite(led1,LOW);
   digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
  }
  Serial.println(reading);
       myserv.write(y);
       delay(20);
  
       }
      int enter2=digitalRead(sensEnter);
       while( enter2==1)
       {
       enter2=digitalRead(sensEnter);
       //ldr sensor
       /////////////////////////////
        reading=analogRead(sensor);
  if(reading>=300)
  {
  digitalWrite(led1,HIGH);
   digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
  }
  else if(reading<300)
  {
  digitalWrite(led1,LOW);
   digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
  }
 //////////////////////////
        }
        count++;
        for(int y=90;y>=0;y--)
        {
          
          //ldr sensor
          ////////////////////////
   reading=analogRead(sensor);
  if(reading>=300)
  {
  digitalWrite(led1,HIGH);
   digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
  }
  else if(reading<300)
  {
  digitalWrite(led1,LOW);
   digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
  }
////////////////////////////////
          myserv.write(y);
           delay(20);
  
           }
        
  
  }
  
   //displaying 
  if(count==0)
  {
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
    digitalWrite(e,HIGH);
    digitalWrite(f,HIGH);
    digitalWrite(g,LOW);
  }
  else if(count==1)
  {
    digitalWrite(a,LOW);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,LOW);
    digitalWrite(e,LOW);
    digitalWrite(f,LOW);
    digitalWrite(g,LOW);
  
  }
  else if(count==2)
  {
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(c,LOW);
    digitalWrite(d,HIGH);
    digitalWrite(e,HIGH);
    digitalWrite(f,LOW);
    digitalWrite(g,HIGH);
  
  
  }
  
  else if(count==3)
  {
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
    digitalWrite(e,LOW);
    digitalWrite(f,LOW);
    digitalWrite(g,HIGH);
  
  
  
  }
  else if(count==4)
  {
    digitalWrite(a,LOW);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,LOW);
    digitalWrite(e,LOW);
    digitalWrite(f,HIGH);
    digitalWrite(g,HIGH);
  
  }
  else if(count==5)
  {
  
    digitalWrite(a,HIGH);
    digitalWrite(b,LOW);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
    digitalWrite(e,LOW);
    digitalWrite(f,HIGH);
    digitalWrite(g,HIGH);
  }
  
  //////////////////////
  enter=1;
  leave=1;
 
  // ldr sensor
  ///////////////////
 reading=analogRead(sensor);
  if(reading>=300)
  {
  digitalWrite(led1,HIGH);
   digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
  }
  else if(reading<300)
  {
  digitalWrite(led1,LOW);
   digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
  }
  /////////////////////////
}
