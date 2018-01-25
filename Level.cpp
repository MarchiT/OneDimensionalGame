#include "Level.h"

Level::Level() {
	field[end - 1] = 'E';
}

void Level::changeEnd(int new_end) {
	end = new_end;
	field[new_end - 1] = 'E';
}

void Level::changeField(char* new_field, int new_end) {
	field = new_field;

	changeEnd(new_end);
}

int Level::getEnd() {
	return end;
}

char * Level::getField() {
	return field;
}
