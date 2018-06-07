#include "PassiveEnemy.h"

PassiveEnemy::PassiveEnemy(int location, int size, char* map)
	: Enemy(location, size, map)
{}

void PassiveEnemy::collision(Player& player) {
	if (within_hitbox(player.index) && schemes[index].interact) {
		player.index = 0;
	}
}
