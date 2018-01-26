#ifndef PROP_H_
#define PROP_H_

#include <cstring>

class Prop {
public:
	int start_index;
	
	char* scheme;
	char* field;

	char hitbox_start;
	char hitbox_end;
	
	int size() {
		return strlen(scheme);
	}

	virtual void draw() = 0;

	virtual bool collision(int player_index) = 0;

	Prop(int start_index, char* scheme, char* field, int hitbox_start, int hitbox_end)
		: start_index(start_index), scheme(scheme), field(field), hitbox_start(hitbox_start), hitbox_end(hitbox_end)
	{
		//validation
		if (!(start_index > 0 && start_index + strlen(scheme) < strlen(field))
			&& (strlen(scheme) > 0)
			&& (hitbox_start >= 0 && hitbox_start < strlen(scheme) - 1)
			&& (hitbox_end > 0 && hitbox_end < strlen(scheme) - 2))
			return;
	}

};

#endif //PROP_H_