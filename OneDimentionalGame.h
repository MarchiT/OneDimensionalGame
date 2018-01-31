#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#include <vector>

#include "constants\specifications.h"
#include "constants\game_options.h"

#include "Player.h"
#include "Level.h"
#include "Prop.h"
#include "PassiveEnemy.h"

#include "StandardStory.h"

class OneDimentionalGame {
private:
	Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRBW + NEO_KHZ800);

	Player player;

	std::vector<Level> levels;
	int level_index = 0;

	bool on = true;

public:
	OneDimentionalGame(int story_type = DEFAULT);

	void run();
	
	void add_level(int end = NUM_LEDS, const char* map = NULL);

	void add_props(int lvl, int size, int location);

private:
	void init();

	bool final();

	void refreshScreen();
	void upload_colors();
	void blink_player();
	
	void position_player(char direction);
	void move_player();

	void create_standard_story();
};