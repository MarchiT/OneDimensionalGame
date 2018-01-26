#ifndef PLAYER_H_
#define PLAYER_H_

class Player {

public:
	int index;
	char type;

	unsigned long blink_time;
	char blink_speed;

	Player()
		: index(0), type('P'), blink_time(0), blink_speed(50)
	{}
};

#endif //PLAYER_H_