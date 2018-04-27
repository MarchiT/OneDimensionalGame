#include "OneDimensionalGame.h"

OneDimensionalGame::OneDimensionalGame(int story_type) {
	switch (story_type) {
	case 0: create_standard_story(); break;
	case 1: break;

	default: create_standard_story(); break;
	}

	init();
}

void OneDimensionalGame::init() {
	#if defined (__AVR_ATtiny85__)
		if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
	#endif

	strip.setBrightness(BRIGHTNESS);
	strip.begin();
	strip.show();
}

void OneDimensionalGame::run() {

	if (levels[level_index].collided(player.index)) {
		player.index = 0;
	}

	if (final()) {
		// go back to the beginning of the level
		player.index = 0;
		level_index++;

		if (level_index == levels.size()) {
			level_index = 0;
		}
	}
	
	levels[level_index].draw_props();

	move_player();

	refreshScreen();
}

bool OneDimensionalGame::final() {
	return levels[level_index].map[player.index] == 'E';
}

void OneDimensionalGame::refreshScreen() {
	if (on) blink_player();

	levels[level_index].cast_map_to_field(player);
	upload_colors();
}

void OneDimensionalGame::blink_player() {
	if ((player.blink_time + player.blink_speed) < millis()) {
		player.blink_time = millis();
		player.type = (player.type == 'P') ? 'p' : 'P';
	}
}

void OneDimensionalGame::upload_colors() {
	for (int i = 0; i < NUM_LEDS; i++) {
		uint32_t color = levels[level_index].field[i];
		strip.setPixelColor(i, color);
	}
	strip.show();
}

//add more chars for direction - pickup, pause, etc.
void OneDimensionalGame::position_player(char direction) {
	switch (direction)
	{
	case 'U':
		if (player.index < (levels[level_index].end-1))
			player.index++;
		break;
	case 'D':
		if (player.index > 0)
			player.index--;
		break;
	case 'R':
		if (player.index < (levels[level_index].end - 1))
			player.index++;
		break;
	case 'L':
		if (player.index > 0)
			player.index--;
		break;
	case 'Z':
		on = !on;
		break;
	default:
		break;
	}
}

void OneDimensionalGame::move_player() {
	if (Serial2.available()) {
		char direction = Serial2.read();
		Serial.write(direction);

		position_player(direction);
	}

	if (Serial.available()) {
		Serial2.write(Serial.read());
	}
}

// void OneDimensionalGame::move_player_hardware() {
// 	char input[8];
// 	Serial3.readBytes(input, 8); //LEUP pp 

// 	Serial.print("INPUT: ");
// 	Serial.println(input);

// 	//parse input if joystick is used

// 	position_player(input[0]);
// }

void OneDimensionalGame::add_level(int end, const char * map) {
	if (map != NULL)
		levels.push_back(Level::new_level(map, end));
	else
		levels.push_back(Level::new_level(StandardStory::MAP_DEFAULT, end));
}


void OneDimensionalGame::add_props(int lvl, int size, int location) {
	
	PassiveEnemy* p = new PassiveEnemy(location, size, levels[lvl].map);
	
	p->add_scheme('b', 70, false);
	p->add_scheme('B', 70, true);

	levels[lvl].props.push_back(p);
}

PassiveEnemy* OneDimensionalGame::add_prop(int lvl, int size, int location) {
	PassiveEnemy* p = new PassiveEnemy(location, size, levels[lvl].map);
	levels[lvl].props.push_back(p);
	return p;
}