#include "Item.h"

Item::Item(int location, char* map)
    : Prop(location, 1, map)
{
    add_scheme('Z', 30, true);
    add_scheme('W', 30, true);
}

void Item::draw() {
    if (++state < schemes[index].frequency) {
		for (int i = location - 1; i < location + size - 1; i++) {
			map[i] = schemes[index].design;
		}
	} else {
		state = 0;
		if (++index == schemes.size()) index = 0;
	}
}

void Item::collision(Player* player) {
    if (within_hitbox(player->index) && player->get_pickup) {
        player->items++;
        player->get_pickup = false;
    }
}