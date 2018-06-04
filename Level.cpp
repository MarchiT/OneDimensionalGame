#include "Level.h"

Level::Level(char* new_map, int new_end) {
	set_map(new_map);
	set_end(new_end);
}

Level Level::new_level(const char * new_map, int new_end)
{
	char* f = new char[NUM_LEDS];
	for (int i = strlen(new_map); i < NUM_LEDS; i++) {
		f[i] = 0;
	}
	for (int i = 0; i < strlen(new_map); i++) {
		f[i] = new_map[i];
	}

	Level l(f, new_end);
	return l;
}

void Level::set_end(int new_end) {
	end = new_end;
	map[new_end - 1] = 'E';
}

void Level::set_map(char* new_map) {
	map = new_map;
}

void Level::cast_map_to_field() {
	for (int i = 0; i < NUM_LEDS; i++) {
		switch (map[i]) {
		case 'R': field[i] = RED; break;
		case 'G': field[i] = GREEN; break;
		case 'B': field[i] = BLUE; break;

		case 'E': field[i] = GREEN; break;

		case 'Y': field[i] = YELLOW; break;
		case 'W': field[i] = WHITE; break;
		case 'Z': field[i] = OFF; break;

		case 'a': field[i] = STUFFLED_GREEN; break;
		case 'b': field[i] = PASTEL_ORANGE; break;
		case 'c': field[i] = PASTEL_RED; break;
		case 'd': field[i] = EH_BLUE; break;
		case 'g': field[i] = CYAN; break;
		case 'e': field[i] = EH_GREEN; break;

		case 'M': field[i] = PURPLE; break;
		case 'f': field[i] = MIDNIGHT_BLUE; break;
		case 'h': field[i] = ROYAL_BLUE; break;
		case 'i': field[i] = POWDER_BLUE; break;

		default:  field[i] = OFF; break;
		}
	}
}


void Level::collided(Player* player) {
	for (Prop* p : props) {
		p->collision(player);
	}
}

void Level::draw_props() {
	for (Prop* p : props) {
		p->draw();
	}
}