#ifndef PASSIVE_ENEMY_H_
#define PASSIVE_ENEMY_H_

#include "Enemy.h"


class PassiveEnemy : public Enemy {

public:
	PassiveEnemy(int location, int size, char* map);

	void draw();

	bool collision(int player_index);

};

#endif //PASSIVE_ENEMY_H_