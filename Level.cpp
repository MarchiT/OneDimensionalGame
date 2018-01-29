#include "Level.h"

Level::Level() {
}

Level Level::new_level(const char * new_map, int new_end)
{
	//for now, new_map must be NUM_LEDS 
	char* f = new char[NUM_LEDS];
	for (int i = 0; i < NUM_LEDS; i++) {
		f[i] = new_map[i];
	}

	Level l;
	l.init(f, new_end);
	return l;
}

void Level::set_end(int new_end) {
	end = new_end;
	map[new_end - 1] = 'E';
}

void Level::set_map(char* new_map) {
	map = new_map;
}

void Level::init(char* new_map, int new_end) {
	set_map(new_map);
	set_end(new_end);
}

void Level::cast_map_to_field(Player player) {
	for (int i = 0; i < NUM_LEDS; i++) {
		switch (map[i]) {
		case 'R': field[i] = RED; break;
		case 'G': field[i] = GREEN; break;
		case 'B': field[i] = BLUE; break;

		case 'l': field[i] = RED; break;
		case 'E': field[i] = GREEN; break;
		case 'M': field[i] = PURPLE; break;
		default:  field[i] = OFF; break;
		}
		if (player.type == 'P')
			field[player.index] = WHITE;
		else
			field[player.index] = PURPLE;
	}
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

	map[end - 1] = 'E'; //why don't you draw the end before this
}