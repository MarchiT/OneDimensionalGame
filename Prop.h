#ifndef PROP_H_
#define PROP_H_

#include <vector>

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
public:
	int state = 0;
	int index = 0;
	
	int location;
	int size;
	
	char* map;
	Hitbox hitbox;

	std::vector<Scheme> schemes;


	Prop(int location, int size, char* map);

	void add_scheme(char design, int frequency, bool dangerous);

	bool within_hitbox(int player_index);

	void init_default_hitbox();


	virtual void draw() = 0;

	virtual bool collision(int player_index) = 0;

};

#endif //PROP_H_