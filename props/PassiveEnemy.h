#ifndef PASSIVE_ENEMY_H_
#define PASSIVE_ENEMY_H_

#include "Enemy.h"


class PassiveEnemy : public Enemy {
public:
	PassiveEnemy(int location, int size, char* map)
	: Enemy(location, size, map)
	{}
	
	void collision(Player& player) {
		if (within_hitbox(player.index) && schemes[index].interact) {
			player.index = 0;
		}
	}
};

#endif //PASSIVE_ENEMY_H_