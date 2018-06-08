#ifndef RUSH_ENEMY_H_
#define RUSH_ENEMY_H_

#include "Enemy.h"

class RushEnemy : public Enemy {
    int move_f = 0;
public:
    RushEnemy(char* map)
        :Enemy(0, 0, map)
    {
        add_scheme('c', 70, false); //could be map colour maybe
        add_scheme('R', 70, true);
    }

    void draw() {
        if (++move_f >= 90 && size < 143) {
            move_f = 60;
            size++;
            hitbox.start = 1;
            hitbox.end++;
        }
        Prop::draw();
    }

    void collision(Player& player) {
        if (size == player.index) {
            move_f = 0;
            player.index = 0;

            size = 0;
            location = 0;
            hitbox.end = 0;
        }
    }
};


#endif //RUSH_ENEMY_H_