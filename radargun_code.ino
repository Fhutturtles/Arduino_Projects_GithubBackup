
#include <Servo.h>

///this is the distance sensor stuff
const int trigPin4 = 4;
const int echoPin5 = 5;
const int trigPin2 = 2;
const int echoPin3 = 3;
const int trigPin11 = 11;
const int echoPin12 = 12;
unsigned long currentTime = 0;
const unsigned long eventinterval = 200;
unsigned long previoustime = 0;
unsigned long duration1 = 0;
unsigned long distance1 = 0;
unsigned long duration2 = 0;
unsigned long distance2 = 0;
unsigned long duration3 = 0;
unsigned long distance3 = 0;


Servo myservo; 
boolean serv = false;
int x = 0;


void setup() {
  // put your setup code here, to run once:
 myservo.attach(10);
   myservo.write(x);
  Serial.begin(9600);
 
  pinMode(trigPin4, OUTPUT);
  digitalWrite(trigPin4, LOW);
  pinMode(echoPin5, INPUT);
   pinMode(trigPin2, OUTPUT);
  digitalWrite(trigPin2, LOW);
  pinMode(echoPin3, INPUT);
  pinMode(trigPin11, OUTPUT);
  digitalWrite(trigPin11, LOW);
  pinMode(echoPin12, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
currentTime = millis();
sensor1();
sensor2();
sensor3();
Serial.print("--Sensor#1---");
Serial.print(distance1);
Serial.print("--Sensor#2---");
Serial.print(distance2);
Serial.print("--Sensor#3---");
Serial.print(distance3);
Serial.print("--Servo location--");
Serial.print(x);
Serial.println();
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
  x = x+10;
  myservo.write(x); 
}
if(serv == true)
{
  x = x-10;
  myservo.write(x);
}
}



void sensor1()
{
  if(currentTime - previoustime >= eventinterval)
{
  digitalWrite(trigPin4, HIGH);
}
if(currentTime - previoustime+10 >= eventinterval)
{
  digitalWrite(trigPin4, LOW);
  duration1 = pulseIn(echoPin5, HIGH);
}
distance1 = (duration1*.0343)/2;

}


void sensor2()
{
  if(currentTime - previoustime >= eventinterval)
{
  digitalWrite(trigPin2, HIGH);
}
if(currentTime - previoustime+10 >= eventinterval)
{
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin3, HIGH);
}
distance2 = (duration2*.0343)/2;

}
void sensor3()
{
  if(currentTime - previoustime >= eventinterval)
{
  digitalWrite(trigPin11, HIGH);
}
if(currentTime - previoustime+10 >= eventinterval)
{
  digitalWrite(trigPin11, LOW);
  duration3 = pulseIn(echoPin12, HIGH);
}
distance3 = (duration3*.0343)/2;

}
