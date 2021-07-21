#include <Servo.h>

///this is the distance sensor stuff
const int trigPin2 = 2;
const int echoPin3 = 3;
//////
const int trigPin5 = 5;
const int echoPin4 = 4;
//////
const int trigPin7 = 7;
const int echoPin6 = 6;
/////
const int trigPin9 =9;
const int echoPin8 = 8;
////
unsigned long currentTime = 0;
const unsigned long eventinterval = 50;
unsigned long previoustime = 0;

unsigned long duration1 = 0;
unsigned long distance1 = 0;

unsigned long duration2 = 0;
unsigned long distance2 = 0;

unsigned long duration3 = 0;
unsigned long distance3 = 0;

unsigned long duration4 = 0;
unsigned long distance4 = 0;
////this is the servo motor stuff
Servo myservo; 
boolean serv = false;
int x = 0;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(10);
  myservo.write(x);
  Serial.begin(9600);
  
  pinMode(2,OUTPUT);
digitalWrite(2, LOW);
pinMode(3, INPUT);

  pinMode(5, OUTPUT);
  digitalWrite(5, LOW);
  pinMode(4, INPUT);
  
   pinMode(7, OUTPUT);
  digitalWrite(7, LOW);
  pinMode(6, INPUT);
  
  pinMode(9, OUTPUT);
  digitalWrite(9, LOW);
  pinMode(8, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
currentTime = millis();
sensor1();
sensor2();
sensor3();
sensor4();
Serial.print("--Sensor#1---");
Serial.print(distance1);
Serial.print("--Sensor#2---");
Serial.print(distance2);
Serial.print("--Sensor#3---");
Serial.print(distance3);
Serial.print("--Sensor#4---");
Serial.print(distance4);
Serial.print("--Servo location--");
  servocode();
  Serial.print(x);
Serial.println();

//digitalWrite(13, LOW);

}

void sensor1()
{
  if(currentTime - previoustime >= eventinterval)
{
  digitalWrite(trigPin2, HIGH);
}
if(currentTime - previoustime+10 >= eventinterval)
{
  digitalWrite(trigPin2, LOW);
  duration1 = pulseIn(echoPin3, HIGH);
}
distance1 = (duration1*.0343)/2;

}

void sensor2()
{
  if(currentTime - previoustime >= eventinterval)
{
  digitalWrite(trigPin5, HIGH);
}
if(currentTime - previoustime+10 >= eventinterval)
{
  digitalWrite(trigPin5, LOW);
  duration2 = pulseIn(echoPin4, HIGH);
}
distance2 = (duration2*.0343)/2;

}

void sensor3()
{
  if(currentTime - previoustime >= eventinterval)
{
  digitalWrite(trigPin7, HIGH);
}
if(currentTime - previoustime+10 >= eventinterval)
{
  digitalWrite(trigPin7, LOW);
  duration3 = pulseIn(echoPin6, HIGH);
}
distance3 = (duration3*.0343)/2;

}

void sensor4()
{
  if(currentTime - previoustime >= eventinterval)
{
  digitalWrite(trigPin9, HIGH);
}
if(currentTime - previoustime+10 >= eventinterval)
{
  digitalWrite(trigPin9, LOW);
  duration3 = pulseIn(echoPin8, HIGH);
}
distance3 = (duration3*.0343)/2;

}


void servocode()
{
  if(x >= 160)
{
  serv = true;
}
if(x <= 110)
{
  serv = false;
}
if(serv == false)
{
  x+=10;
  myservo.write(x); 
}
if(serv == true)
{
  x-=10;
  myservo.write(x);
}
}
