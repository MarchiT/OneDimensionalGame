#ifndef ENEMY_H_
#define ENEMY_H_

#include "Prop.h"

//Enemies iteract with Player: by being either dangerous or safe to pass through
class Enemy : public Prop {
public:
	Enemy(int location, int size, char* map)
		: Prop(location, size, map)
	{}

};

#endif //ENEMY_H_