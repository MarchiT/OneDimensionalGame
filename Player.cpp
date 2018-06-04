#include "Player.h"

Player::Player()
	: index(0), type('P'), blink_time(0), blink_speed(50)
{}

void Player::clean() {
	index = 0;
	ammo = 0;
	items = 0;
}

Player::Player(int index, char type, unsigned long blink_time, char blink_speed)
	: index(index), type(type), blink_time(blink_time), blink_speed(blink_speed)
{}

void Player::draw(uint32_t* field, int level_end) {
	int start = index - items;
	if (start < 0) start = 0;

	int end = index + ammo + 1;
	if (end > level_end) end = level_end;	


	for (int i = start; i < index; i++) {
		field[i] = WHITE;
	}
	field[index] = type == 'P' ? WHITE : OFF;
	for (int i = index + 1; i < end; i++) {
		field[i] = WHITE;
	}
}