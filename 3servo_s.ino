#include <Servo.h>
const int M1 = 4;
const int M2 = 5;
const int M3 = 6;
const int trigPin8 = 8;
const int echoPin9 = 9;
Servo myservo1; 
Servo myservo2; 
Servo myservo3; 
boolean serv = false;
int x = 0;


unsigned long currentTime = 0;
const unsigned long eventinterval = 200;
unsigned long previoustime = 0;
unsigned long duration1 = 0;
unsigned long distance1 = 0;
void setup() {
  // put your setup code here, to run once:


 myservo1.attach(M1);
 myservo2.attach(M2);
 myservo3.attach(M3);
 myservo1.write(x);
 myservo2.write(x);  
 myservo3.write(x);
  Serial.begin(9600);


pinMode(trigPin8, OUTPUT);
  digitalWrite(trigPin8, LOW);
  pinMode(echoPin9, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  currentTime = millis();
sensor1();
Serial.print("Sensor#1---");
Serial.print(distance1);
Serial.print("---");

if(x >= 180)
{
  serv = true;
}
if(x <= 0)
{
  serv = false;
}
if(serv == false)
{
  x = x+20;
 myservo1.write(x);
 myservo2.write(x);  
 myservo3.write(x);
}
if(serv == true)
{
  x = x-20;
 myservo1.write(x);
 myservo2.write(x);  
 myservo3.write(x);
}
Serial.print(" Servo Loaction---");
Serial.print(x);
Serial.println();
}



void sensor1()
{
  if(currentTime - previoustime >= eventinterval)
{
  digitalWrite(trigPin8, HIGH);
}
if(currentTime - previoustime+10 >= eventinterval)
{
  digitalWrite(trigPin8, LOW);
  duration1 = pulseIn(echoPin9, HIGH);
  digitalWrite(echoPin9, LOW);
}
distance1 = (duration1*.0343)/2;

}
