#include <TimerOne.h>
unsigned long count = 0;
unsigned long tempCount = 5;
byte flag  = 0;
int x = 0;
void timer()
{
  count++;
 
}

const byte ledPin = 3;
const byte interruptPin = 2;
volatile byte state = LOW;
int val=0;

void setup() {
Timer1.initialize(1000000);// 1 Sec delay
Timer1.attachInterrupt(timer);
pinMode(ledPin, OUTPUT);
pinMode(interruptPin, INPUT_PULLUP);
attachInterrupt(digitalPinToInterrupt(interruptPin), test, CHANGE);
Serial.begin(9600);
}

void loop() {
digitalWrite(ledPin, state);
//Serial.println(val/2);
//Serial.print("Count ");
//Serial.println (count);
if (((count - tempCount == 3)&& state == HIGH)|| flag)
{
  flag = 1;
  
  if(x >0){
  Serial.println("Charging...");
  }
  if (x==0 && state == HIGH)
  {
    Serial.println("Starting Charge.");
    }
    x++;
  }
  else
  {
    Serial.println("Not Charging");
    x=0;
    }
}

void test() {
state = !state;
val++;
tempCount = count;
if (state == LOW)
{
  flag=0;
  }
}
