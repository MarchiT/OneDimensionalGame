#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#include <vector>

#include "constants/specifications.h"
#include "constants/game_options.h"

#include "Player.h"
#include "Level.h"
#include "Prop.h"
#include "PassiveEnemy.h"
#include "ActiveEnemy.h"
#include "RushEnemy.h"
#include "Item.h"

#include "StandardMaps.h"

class OneDimensionalGame {
private:
	Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRBW + NEO_KHZ800);

	Player player;

	std::vector<Level> levels;
	int level_index = 0;

	bool on = true;

public:
	OneDimensionalGame(int story_type = DEFAULT);

	void run();
	
	void add_level(const char* map = NULL, int end = NUM_LEDS);

	void add_props(int lvl, int size, int location);
	PassiveEnemy* add_passive_enemy(int lvl, int size, int location);
	ActiveEnemy* add_active_enemy(int lvl, int size, int location);
	RushEnemy* add_rush_enemy(int lvl);
	Item* add_item(int lvl, int location);

private:
	void init();

	bool final();

	void refreshScreen();
	void upload_colors();
	void blink_player();
	
	void position_player(char direction);
	void move_player_software();
	void move_player_hardware();
	void move_player_hardware_reverse();

	void create_standard_story();
};