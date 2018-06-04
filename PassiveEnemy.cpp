#include "PassiveEnemy.h"

PassiveEnemy::PassiveEnemy(int location, int size, char* map)
	: Enemy(location, size, map)
{}

void PassiveEnemy::draw() {
	if (++state < schemes[index].frequency) {
		for (int i = location - 1; i < location + size - 1; i++) {
			map[i] = schemes[index].design;
		}
	} else {
		state = 0;
		if (++index == schemes.size()) index = 0;
	}
}

void PassiveEnemy::collision(Player* player) {
	if (within_hitbox(player->index) && schemes[index].dangerous) {
		player->index = 0;
	}
}
