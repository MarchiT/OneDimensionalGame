#include "Item.h"

Item::Item(int location, char* map)
    : Prop(location, 1, map)
{
    add_scheme('Z', 30, true);
    add_scheme('W', 30, true);
}

void Item::collision(Player* player) {
    if (within_hitbox(player->index) && player->get_pickup) {
        player->items++;
        player->get_pickup = false;
    }
}