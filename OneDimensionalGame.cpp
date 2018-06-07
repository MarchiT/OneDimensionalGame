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

	levels[level_index].collided(player);

	if (final()) {
		// go back to the beginning of the level
		player.clean();
		level_index++;

		if (level_index == levels.size()) {
			level_index = 0;
			//lock here until restart button is pressed
			while(digitalRead(SW));
		}
	}
	
	levels[level_index].draw_props();

	move_player_hardware();

	refreshScreen();
}

bool OneDimensionalGame::final() {
	return levels[level_index].map[player.index] == 'E';
}

void OneDimensionalGame::refreshScreen() {
	if (on) blink_player();

	levels[level_index].cast_map_to_field();
	player.draw(levels[level_index].field, levels[level_index].end); //Player draws itself directly onto the field
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
	case 'R': //selects through items from right
		player.hover_item--;
		if (player.hover_item < 1)
			player.hover_item = player.items;	
		Serial.println((int)player.hover_item);
		break;
	case 'L': //selects through items from left
		player.hover_item++;

		if (player.hover_item > player.items)
			player.hover_item = 1;
		break;
	case 'u':
		if (player.index < (levels[level_index].end-1))
			player.index++;
		break;
	case 'd':
		if (player.index > 0)
			player.index--;
		break;
	case 'r':
		if (player.index < (levels[level_index].end - 1))
			player.index++;
		break;
	case 'l':
		if (player.index > 0)
			player.index--;
		break;
	case 'Z': //Joystick Switch
		player.get_pickup = true;
		break;	
	case 'C': //Square button away from joystick | CHOOSE, select
		if (player.hover_item != 0){
			// if (--player.items == 0) player.hover_item = 0;
			player.items--;
			player.hover_item = 0;			
		}
		break;
	case 'P': //Square button next to joystick | stop selecting 
		if(player.items) player.hover_item = (player.hover_item) ? 0 : 1;
		break;
	default:
		break;
	}
}

void OneDimensionalGame::move_player_software() {
	if (Serial2.available()) {
		char direction = Serial2.read();
		Serial.write(direction);

		position_player(direction);
	}

	if (Serial.available()) {
		Serial2.write(Serial.read());
	}
}

unsigned long speed_time = 0;

void OneDimensionalGame::move_player_hardware() {

	if (Serial3.available())
	{
		char input = Serial3.read();

		Serial.print("INPUT: ");
		Serial.println(input);

		position_player(input);
	}
}

void OneDimensionalGame::move_player_hardware_reverse() {
	if (Serial3.available())
	{
		char input = Serial3.read();
		Serial.print("INPUT: ");
		Serial.println(input);

		switch(input)
		{
			case 'u': input = 'U'; break;
			case 'd': input = 'D'; break;
			case 'r': input = 'R'; break;
			case 'l': input = 'L'; break;
		}

		position_player(input);
	}
}

void OneDimensionalGame::add_level(const char * map, int end) {
	if (map != NULL)
		levels.push_back(Level::new_level(map, end));
	else
		levels.push_back(Level::new_level(StandardMaps::MAP_DEFAULT, end));
}


void OneDimensionalGame::add_props(int lvl, int size, int location) {
	
	PassiveEnemy* p = new PassiveEnemy(location, size, levels[lvl].map);
	
	p->add_scheme('b', 70, false);
	p->add_scheme('B', 70, true);

	levels[lvl].props.push_back(p);
}

PassiveEnemy* OneDimensionalGame::add_passive_enemy(int lvl, int size, int location) {
	PassiveEnemy* p = new PassiveEnemy(location, size, levels[lvl].map);
	levels[lvl].props.push_back(p);
	return p;
}

LockedEnemy* OneDimensionalGame::add_locked_enemy(int lvl, int size, int location) {
	LockedEnemy* l = new LockedEnemy(location, levels[lvl].map, size);
	levels[lvl].props.push_back(l);
	return l;
}

RushEnemy* OneDimensionalGame::add_rush_enemy(int lvl) {
	RushEnemy* m = new RushEnemy(levels[lvl].map);
	levels[lvl].props.push_back(m);
	return m;
}


Item* OneDimensionalGame::add_item(int lvl, int location) {
	Item* i = new Item(location, levels[lvl].map);
	levels[lvl].props.push_back(i);
	return i;
}