#include <OneDimensionalGame.h>

OneDimensionalGame game(CUSTOM);

void setup() {
	pinMode(SW, INPUT_PULLUP);
	Serial.begin(115200);
	Serial.println("Serial initialized");
	Serial2.begin(9600);
	Serial3.begin(115200);

	game.add_level(StandardMaps::MAP_BLANK, 20);
	game.add_props(0, 2, 10);
}

void loop() {
	game.run();
}
 