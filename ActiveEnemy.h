#ifndef ACTIVE_ENEMY_H_
#define ACTIVE_ENEMY_H_

#include "Enemy.h"
#include "PassiveEnemy.h"


class ActiveEnemy : public Enemy {
    int passive_size;
    PassiveEnemy* wall;
    bool activated;

public:
	ActiveEnemy(int location, char* map, int passive_size)
        :Enemy(location, 1, map)
    {
        this->activated = false;
        this->passive_size = passive_size - 1;
        this->wall = new PassiveEnemy(location+1, passive_size, map);
        wall->add_scheme('R', 40, true);
        wall->add_scheme('G', 40, false);
    }

    void draw() {
        Prop::draw();
        wall->draw();
    }

	void collision(Player& player) {
        if (!activated 
            && within_hitbox(player.index) && schemes[index].interact
            && player.items) {
                
            player.items--;
            activated = true;
            wall->remove_schemes();
            wall->add_scheme('R', 300, true);
            wall->add_scheme('G', 300, false);
        }
        
        wall->collision(player);
    }
};

#endif //ACTIVE_ENEMY_H_