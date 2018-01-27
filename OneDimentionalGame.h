#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#include <vector>

#include "colors.h"
#include "constants.h"

#include "Player.h"
#include "Level.h"

#include "Prop.h"

#include "Animations.h"

class OneDimentionalGame {
private:
	Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRBW + NEO_KHZ800);

	Player player;

	std::vector<Level> levels;
	int level_index = 0;

	bool on = true;
	bool default_story = false;

public:
	OneDimentionalGame();

	void run();
	
	void add_level(int end = NUM_LEDS, const char* map = NULL);

	void add_props(int lvl, int size, int location);
	
	void create_own_story();
	void create_default_story();

private:
	void init();

	bool final();

	void refreshScreen();
	void cast_map_to_field();
	void upload_colors();
	void blink_player();
	
	void position_player(char direction);
	void move_player();
};