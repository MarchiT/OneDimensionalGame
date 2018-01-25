#include "Level.h"

Level::Level() {
}

Level Level::new_level(char * new_field, int new_end)
{
	char* f = new char[288];
	for (int i = 0; i < 288; i++) {
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
