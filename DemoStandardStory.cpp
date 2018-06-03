#include "OneDimensionalGame.h"
#include "DemoEnemies.h"


void OneDimensionalGame::create_standard_story() {
    add_level(NUM_LEDS, StandardMaps::MAP_BLANK);

    DemoEnemies::basic_short(add_prop(0, 2, 10));
    DemoEnemies::basic_long(add_prop(0, 4, 15));

	DemoEnemies::disguise(add_prop(0, 2, 21));
	DemoEnemies::colourful_blue(add_prop(0, 3, 25));
}



void DemoEnemies::basic_short(PassiveEnemy *p) {
	p->add_scheme('G', 150, false);
	p->add_scheme('R', 150, true);  
}

void DemoEnemies::basic_long(PassiveEnemy *p) {
	p->add_scheme('G', 300, false);
	p->add_scheme('R', 50, true);  
}

void DemoEnemies::colourful_blue(PassiveEnemy *p) {
	p->add_scheme('f', 60, false);
	p->add_scheme('h', 60, false);
	p->add_scheme('B', 60, false);
	p->add_scheme('R', 60, true);  //MAKE RED MORE SHINY
}

void DemoEnemies::disguise(PassiveEnemy *p) {
	p->add_scheme('c', 70, true);
	p->add_scheme('Z', 90, false);  
}