#include <OneDimentionalGame.h>

OneDimentionalGame game;

void setup() {
  Serial.begin(115200);
  Serial.println("Serial initialized");
  Serial2.begin(9600);
}

void loop() {
  game.run();
}
 