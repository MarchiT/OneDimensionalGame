#ifndef ENEMY_H_
#define ENEMY_H_

#include "Prop.h"

class Enemy : public Prop {
public:
	Enemy(int location, int size, char* map)
		: Prop(location, size, map)
	{}

};

#endif //ENEMY_H_