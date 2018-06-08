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
			while(digitalRead(SW)) {
				rainbowFade2White(3,3,1);
			}
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

		if (player.hover_item > player.items && (player.items))
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
	
	p->add_scheme('G', 100, false);
	p->add_scheme('R', 100, true);

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


byte neopix_gamma[] = {
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  2,  2,  2,  2,  2,  2,  2,
    2,  3,  3,  3,  3,  3,  3,  3,  4,  4,  4,  4,  4,  5,  5,  5,
    5,  6,  6,  6,  6,  7,  7,  7,  7,  8,  8,  8,  9,  9,  9, 10,
   10, 10, 11, 11, 11, 12, 12, 13, 13, 13, 14, 14, 15, 15, 16, 16,
   17, 17, 18, 18, 19, 19, 20, 20, 21, 21, 22, 22, 23, 24, 24, 25,
   25, 26, 27, 27, 28, 29, 29, 30, 31, 32, 32, 33, 34, 35, 35, 36,
   37, 38, 39, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 50,
   51, 52, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 66, 67, 68,
   69, 70, 72, 73, 74, 75, 77, 78, 79, 81, 82, 83, 85, 86, 87, 89,
   90, 92, 93, 95, 96, 98, 99,101,102,104,105,107,109,110,112,114,
  115,117,119,120,122,124,126,127,129,131,133,135,137,138,140,142,
  144,146,148,150,152,154,156,158,160,162,164,167,169,171,173,175,
  177,180,182,184,186,189,191,193,196,198,200,203,205,208,210,213,
  215,218,220,223,225,228,231,233,236,239,241,244,247,249,252,255 };


// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t OneDimensionalGame::Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3,0);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3,0);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0,0);
}

uint8_t red(uint32_t c) {
  return (c >> 16);
}
uint8_t green(uint32_t c) {
  return (c >> 8);
}
uint8_t blue(uint32_t c) {
  return (c);
}


void OneDimensionalGame::rainbowFade2White(uint8_t wait, int rainbowLoops, int whiteLoops) {
  float fadeMax = 100.0;
  int fadeVal = 0;
  uint32_t wheelVal;
  int redVal, greenVal, blueVal;

  for(int k = 0 ; k < rainbowLoops ; k ++){
    
    for(int j=0; j<256; j++) { // 5 cycles of all colors on wheel

      for(int i=0; i< strip.numPixels(); i++) {

        wheelVal = Wheel(((i * 256 / strip.numPixels()) + j) & 255);

        redVal = red(wheelVal) * float(fadeVal/fadeMax);
        greenVal = green(wheelVal) * float(fadeVal/fadeMax);
        blueVal = blue(wheelVal) * float(fadeVal/fadeMax);

        strip.setPixelColor( i, strip.Color( redVal, greenVal, blueVal ) );

      }
      //First loop, fade in!
      if(k == 0 && fadeVal < fadeMax-1) {
          fadeVal++;
      }
      //Last loop, fade out!
      else if(k == rainbowLoops - 1 && j > 255 - fadeMax ){
          fadeVal--;
      }
        strip.show();
        delay(wait);
    }
  }
  delay(500);

  for(int k = 0 ; k < whiteLoops ; k ++){
    for(int j = 0; j < 256 ; j++){
        for(uint16_t i=0; i < strip.numPixels(); i++) {
            strip.setPixelColor(i, strip.Color(0,0,0, neopix_gamma[j] ) );
          }
          strip.show();
        }
        delay(2000);
    for(int j = 255; j >= 0 ; j--){
        for(uint16_t i=0; i < strip.numPixels(); i++) {
            strip.setPixelColor(i, strip.Color(0,0,0, neopix_gamma[j] ) );
          }
          strip.show();
        }
  }
  delay(500);
}
