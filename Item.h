#ifndef ITEM_H_
#define ITEM_H_

#include "Prop.h"

class Item : public Prop {
public:
    Item(int location, char* map);

    void collision(Player* player);
};

#endif //ITEM_H_