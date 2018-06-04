#ifndef PROP_H_
#define PROP_H_

#include <vector>
#include "Player.h"

struct Hitbox {
	int start;
	int end;
};

struct Scheme {
	char design;
	int frequency;
	bool dangerous = false;
};

class Prop {
private:
	Scheme create_scheme(char design, int frequency, bool dangerous);

	void set_hitbox(int start, int end);

public:

	Prop(int location, int size, char* map, int hitbox_start=0, int hitbox_end=0);
	
	void add_scheme(char design, int frequency, bool dangerous);
	
	virtual void draw() = 0;

	virtual void collision(Player* player) = 0;

protected:	
	int state = 0;
	int index = 0;
	
	int location;
	int size;
	
	char* map;
	Hitbox hitbox;

	std::vector<Scheme> schemes;


	bool within_hitbox(int player_index);
};

#endif //PROP_H_