#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#include <stdint.h>
#include <vector>

#include "colors.h"
#include "constants.h"

#include "Player.h"
#include "Level.h"

class OneDimentionalGame {
private:
	Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRBW + NEO_KHZ800);

	Player player;

	std::vector<Level> levels;
	int level_index = 0;

public:
	OneDimentionalGame();

	void init();

	void run();

	bool final();

	void refreshScreen();
	void cast_field();
	void upload_colors();
	void blink_player();
	
	void position_player(char direction);
	void move_player();

	void add_level(int end = NUM_LEDS, char* field = NULL);
};