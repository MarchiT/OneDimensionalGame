#include <SoftwareSerial.h>

#define LEFT 10
#define RIGHT 7
#define UP 8
#define DOWN 9

#define CHOOSE 11
#define PAUSE 12

#define X 0
#define Y 1
#define PICKUP 4

#define LED_PIN 13

SoftwareSerial sender(5, 6); // RX, TX


void setup()
{
  pinMode(LEFT, INPUT_PULLUP);
  pinMode(RIGHT, INPUT_PULLUP);
  pinMode(UP, INPUT_PULLUP);
  pinMode(DOWN, INPUT_PULLUP);

  pinMode(CHOOSE, INPUT_PULLUP);
  pinMode(PAUSE, INPUT_PULLUP);

  pinMode(X, INPUT);
  pinMode(Y, INPUT);
  pinMode(PICKUP, INPUT_PULLUP);

  pinMode(LED_PIN, OUTPUT); //decide what to do with the LED
  

  Serial.begin(115200);
  Serial.print("In to work!");
  sender.begin(115200);
}

char output = 'X';
unsigned long speed_time = 0;
int yPosition = 500;
int xPosition = 500;

void loop()
{
  if((speed_time + 120) < millis() ) {
      speed_time = millis();
      
      yPosition = analogRead(Y);
      xPosition = analogRead(X);

        if (digitalRead(UP) == 0) {
          output = 'U';
        } else if (!digitalRead(DOWN)) {
          output = 'D';
        } else if (!digitalRead(LEFT)) {
          output = 'L';
        } else if (!digitalRead(RIGHT)) {
          output = 'R';
        } else if (!digitalRead(CHOOSE)) {
          output = 'C';
        } else if (!digitalRead(PAUSE)) {
          output = 'P';
        } 
        //clean state -> x:498 y:508
        //right -> 0, left -> 1023
        //up -> 1023, down -> 0 
        else if (yPosition < 400) { 
          int yPosition = 500;
          output = 'd';
        } else if (yPosition > 600) { 
          int yPosition = 500;
          output = 'u';
        } else if (xPosition < 400) { 
          int xPosition = 500;
          output = 'r';
        } else if (xPosition > 600) { 
          int xPosition = 500;
          output = 'l';
        } else if (!digitalRead(PICKUP)) {
          output = 'Z';
        } else {
          output = 'X';
        }

        if (output != 'X') {
          sender.write(output);
        }
  }
}
