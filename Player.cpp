#include "Player.h"

Player::Player()
	: index(0), type('P'), blink_time(0), blink_speed(50)
{}

Player::Player(int index, char type, unsigned long blink_time, char blink_speed)
	: index(index), type(type), blink_time(blink_time), blink_speed(blink_speed)
{}

void Player::draw(uint32_t* field) {
	field[index] = type == 'P' ? WHITE : OFF;
}