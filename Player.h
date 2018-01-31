#ifndef PLAYER_H_
#define PLAYER_H_

class Player {

public:
	int index;
	char type;

	unsigned long blink_time;
	char blink_speed;

	Player();
	Player(int index, char type, unsigned long blink_time, char blink_speed);
};

#endif //PLAYER_H_