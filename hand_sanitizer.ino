#include <Servo.h>

Servo s1;      // Declaring object of servo

int echo=4;       //Creating variables for pins
int trig=5;
int led=6;
long distance,duration; //Variable to store values
void setup()
{
  pinMode(echo,INPUT);  //Configuration of pins
  pinMode(trig,OUTPUT);
  pinMode(led,OUTPUT);
  s1.attach(3);     //.attach(pin_no) function for servo
  Serial.begin(9600); //For starting serial monitor
}

void loop()
{
  digitalWrite(trig,LOW); 
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);  //Sending signal from ultrasonic
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  
  duration=pulseIn(echo,HIGH); //Receving siganl using pulseIn 
  distance=duration/57.2;   //Calculating distance between
                  //object and sensor
  Serial.println(distance);   
  delay(10);
  if(distance<15)     //Condition to start servo
  {
    s1.write(90);   //Starting Servo
    digitalWrite(led,HIGH);
  }
  else
  {
    s1.write(0);
    digitalWrite(led,LOW);
  }
}
