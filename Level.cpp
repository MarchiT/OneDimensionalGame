#include "Level.h"

Level::Level() {
}

Level Level::new_level(const char * new_field, int new_end)
{
	//for now, new_field must be NUM_LEDS 
	char* f = new char[NUM_LEDS];
	for (int i = 0; i < NUM_LEDS; i++) {
		f[i] = new_field[i];
	}

	Level l;
	l.init(f, new_end);
	return l;
}

void Level::set_end(int new_end) {
	end = new_end;
	field[new_end - 1] = 'E';
}

void Level::set_field(char* new_field) {
	field = new_field;
}

void Level::init(char* new_field, int new_end) {
	set_field(new_field);
	set_end(new_end);
}

bool Level::collided(int player_index) {
	if (!props.size()) return false;

	for (Prop* p : props) {
		p->collision(player_index);
	}
}

void Level::draw_props() {
	if (!props.size()) return;

	for (Prop* p : props) {
		p->draw();
	}

	field[end - 1] = 'E'; //why don't you draw the end before this
}