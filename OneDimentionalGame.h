#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#include <vector>

#include "constants\specifications.h"
#include "constants\game_options.h"
#include "constants\colors.h"

#include "Player.h"
#include "Level.h"
#include "Prop.h"

#include "StandartStory.h"


class OneDimentionalGame {
private:
	Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRBW + NEO_KHZ800);

	Player player;

	std::vector<Level> levels;
	int level_index = 0;

	bool on = true;

public:
	OneDimentionalGame(int story_type = 0);

	void run();
	
	void add_level(int end = NUM_LEDS, const char* map = NULL);

	void add_props(int lvl, int size, int location);

private:
	void init();

	bool final();

	void refreshScreen();
	void cast_map_to_field();
	void upload_colors();
	void blink_player();
	
	void position_player(char direction);
	void move_player();

	void create_standart_story();
};