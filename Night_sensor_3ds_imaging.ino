
#include <Servo.h>
Servo myservo; 
///this is the distance sensor stuff
const int trigPin2 = 2;
const int echoPin3 = 3;
//////
const int trigPin4 = 4;
const int echoPin5 = 5;
//////
const int trigPin6 = 6;
const int echoPin7 = 7;
/////
const int trigPin8 = 8;
const int echoPin9 = 9;
////
unsigned long currentTime = 0;
const unsigned long eventinterval = 520;
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

boolean serv = false;
int x = 0;
int num = 5;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(10);
  
  Serial.begin(9600);
  
  pinMode(trigPin2 ,OUTPUT);
digitalWrite(trigPin2 , LOW);
pinMode(echoPin3, INPUT);

  pinMode(trigPin4 , OUTPUT);
  digitalWrite(trigPin4 , LOW);
  pinMode(echoPin5, INPUT);
  
   pinMode(trigPin6 , OUTPUT);
  digitalWrite(trigPin6 , LOW);
  pinMode(echoPin7, INPUT);
  
  pinMode(trigPin8, OUTPUT);
  digitalWrite(trigPin8, LOW);
  pinMode(echoPin9, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
currentTime = millis();
sensor1();
sensor2();
sensor3();
sensor4();
Serial.print("Sensor#1---");
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
if(currentTime - previoustime+1b   >= eventinterval)
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
  digitalWrite(trigPin4, HIGH);
}
if(currentTime - previoustime+1 >= eventinterval)
{
  digitalWrite(trigPin4, LOW);
  duration2 = pulseIn(echoPin5, HIGH);
}
distance2 = (duration2*.0343)/2;

}

void sensor3()
{
  if(currentTime - previoustime >= eventinterval)
{
  digitalWrite(trigPin6, HIGH);
}
if(currentTime - previoustime+1 >= eventinterval)
{
  digitalWrite(trigPin6, LOW);
  duration3 = pulseIn(echoPin7, HIGH);
}
distance3 = (duration3*.0343)/2;

}

void sensor4()
{
  if(currentTime - previoustime >= eventinterval)
{
  digitalWrite(trigPin8, HIGH);
}
if(currentTime - previoustime+1 >= eventinterval)
{
  digitalWrite(trigPin8, LOW);
  duration4 = pulseIn(echoPin9, HIGH);
}
distance4 = (duration3*.0343)/2;

}


void servocode()
{
  if(x >= 120)
{
  serv = true;
}
if(x <= 0)
{
  serv = false;
}
if(serv == false)
{
  x+=num ;
  myservo.write(x); 
}
if(serv == true)
{
  x-=num ;
  myservo.write(x);
}
}
