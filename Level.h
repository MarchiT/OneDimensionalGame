#ifndef LEVEL_H_
#define LEVEL_H_

#include <stdint.h>
#include <vector>

#include "constants.h"

#include "Prop.h"
#include "PassiveEnemy.h"

class Level {

public:
	int end = NUM_LEDS;

	uint32_t filled[NUM_LEDS];
	char* field;
	
	std::vector<Prop*> props;
	
	Level();

	static Level new_level(const char* new_field, int new_end = NUM_LEDS);
	
	bool collided(int player_index);

	void draw_props();
	
private:
	void init(char* new_field, int new_end = NUM_LEDS);

	void set_end(int new_end = NUM_LEDS);
	void set_field(char* new_field);
};

#endif //LEVEL_H_