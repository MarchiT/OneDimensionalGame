#ifndef ENEMY_H_
#define ENEMY_H_

#include "Prop.h"

class Enemy : public Prop {
public:
	Enemy(int start_index, char* scheme, char* field, int hitbox_start, int hitbox_end)
		: Prop(start_index, scheme, field, hitbox_start, hitbox_end)
	{}

};

#endif //ENEMY_H_