#include <OneDimensionalGame.h>

OneDimensionalGame game;

void setup() {
  pinMode(SW, INPUT_PULLUP);
  
  Serial.begin(115200);
  Serial.println("Serial initialized");
  Serial2.begin(9600);
  Serial3.begin(115200);
}

void loop() {
  game.run();
}
 