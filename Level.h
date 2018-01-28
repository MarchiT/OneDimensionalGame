#ifndef LEVEL_H_
#define LEVEL_H_

#include <stdint.h>
#include <vector>

#include "constants\specifications.h"

#include "Prop.h"

class Level {

public:
	int end = NUM_LEDS;

	uint32_t field[NUM_LEDS];
	char* map;
	
	std::vector<Prop*> props;
	
	Level();

	static Level new_level(const char* new_map, int new_end = NUM_LEDS);
	
	bool collided(int player_index);

	void draw_props();
	
private:
	void init(char* new_map, int new_end = NUM_LEDS);

	void set_end(int new_end = NUM_LEDS);
	void set_map(char* new_map);
};

#endif //LEVEL_H_