#ifndef PASSIVE_ENEMY_H_
#define PASSIVE_ENEMY_H_

#include "Enemy.h"


class PassiveEnemy : public Enemy {
private:
	int state = 0;

	//char* scheme2 = state_two_scheme('M'); //okay as long as it compiles after scheme1
	char scheme2[3] = { 'M', 'M', 'M' }; //okay as long as it compiles after scheme1

public:
	PassiveEnemy(int start_index, char* scheme, char* field, int hitbox_start = 0, int hitbox_end = NULL)
		: Enemy(start_index, scheme, field, hitbox_start, hitbox_end)
	{
		hitbox_end = strlen(scheme) - 1; //i think strlen does not work for some reason
	}

	void draw() {
		char* cur_scheme;

		if (state < 70) {
			cur_scheme = scheme;
		} else if (state < 140) {
			cur_scheme = scheme2;
		}
		else {
			state = 0;
		}
		state++; //this should happen for intervals in time, not iterations

		for (int i = start_index - 1, j = 0; i < (size() + start_index - 1); i++, j++)
			field[i] = cur_scheme[j];

	}

	//TODO: change type not to be hard-coded
	//and add more schemes
	bool collision(int player_index) {
		return ((field[player_index] == 'l') &&
			(player_index > (start_index + hitbox_start - 2)));// && player_index < (start_index + hitbox_end))); //this makes no sense for it not to run but yet, it doesn't
	}

private:
	char* state_two_scheme(char type) {
		char new_scheme[strlen(scheme)];
		for (int i = 0; i < strlen(scheme); i++) {
			new_scheme[i] = type;
		}
		return new_scheme;
	}
};

#endif //PASSIVE_ENEMY_H_