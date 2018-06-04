#ifndef LEVEL_H_
#define LEVEL_H_

#include <stdint.h>
#include <vector>
#include <string.h>

#include "constants/specifications.h"
#include "constants/colors.h"

#include "Prop.h"
#include "Player.h"

class Level {
private:
	Level(char* new_map, int new_end = NUM_LEDS);

	void set_end(int new_end = NUM_LEDS);
	void set_map(char* new_map);

public:
	int end = NUM_LEDS;

	uint32_t field[NUM_LEDS];
	char* map;
	
	std::vector<Prop*> props;
	

	static Level new_level(const char* new_map, int new_end = NUM_LEDS);
	
	void cast_map_to_field(Player player);
	
	void collided(Player* player);

	void draw_props();
};

#endif //LEVEL_H_