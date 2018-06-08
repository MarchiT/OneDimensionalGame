#ifndef ITEM_H_
#define ITEM_H_

#include "Prop.h"

class Item : public Prop {
public:
    Item(int location, char* map)
        : Prop(location, 1, map)
    {
        add_scheme('Z', 30, true);
        add_scheme('M', 30, true);
    }

    void collision(Player& player) {
        if (within_hitbox(player.index) && player.get_pickup) {
            player.items++;
            player.get_pickup = false;
        }
    }
};

#endif //ITEM_H_