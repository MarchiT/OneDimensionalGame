#ifndef PLAYER_H_
#define PLAYER_H_

#include <stdint.h>
#include "constants/colors.h"

class Player {

public:
	int index;
	char type;

	unsigned long blink_time;
	char blink_speed;

	Player();
	Player(int index, char type, unsigned long blink_time, char blink_speed);

	void draw(uint32_t* field, int end);

	void clean();

	int ammo = 0;
	int items = 0;

	bool get_pickup = false;
	char hover_item;
};

#endif //PLAYER_H_