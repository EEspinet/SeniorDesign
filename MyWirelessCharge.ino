#define ledPin 9
#define bluetoothPin 2
#define echoPin 12
#define trigPin 11

int state = 0;
int count = 0;

void setup() {
  Serial.begin(9600);//Default communication rate for bluetooth
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(bluetoothPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  digitalWrite(bluetoothPin, HIGH);
}

void loop() {
  
  count = 0;
  for (int i = 0; i < 500; i++)
  {
    if (i < 250)
    {
      digitalWrite(ledPin, HIGH);
      if(count == 0 || count == 25 || count == 50 || count == 75 || count == 100 || 
          count == 125 || count == 150 || count == 175 || count == 200 || count == 225)
          {
            //Serial.write("CHARGING: CONNECTED\n");
            Serial.println("CHARGING: CONNECTED\n");
          }
      delay(50);
    }//End of if statement

    else
    {
      digitalWrite(ledPin, LOW);
      if (count == 250 || count == 275 || count == 300 || count == 325 || count == 350 ||
            count == 375 || count == 400 || count == 425 || count == 450 || count == 475)
        {
//          Serial.write("CHARGING: DISCONNECTED\n");
          Serial.println("CHARGING: DISCONNECTED\n");
        }
        delay(50);
    }//End of else statement
count++;
  }//End of for loop
//  if(Serial.available() > 0)
//  {
//    state = Serial.read();
//  }
//
//  if(state == '0')
//  {
//    digitalWrite(ledPin, LOW);
//    Serial.println("LED: OFF");
//    state = 0;
//  }
//
//  else if(state == '1')
//  {
//    digitalWrite(ledPin, HIGH);
//    Serial.println("LED: ON");
//    state = 0;
//  }
}
