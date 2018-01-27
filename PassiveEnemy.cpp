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

bool PassiveEnemy::collision(int player_index) {
	return (within_hitbox(player_index) && schemes[index].dangerous && (map[player_index] == schemes[index].design));
}
