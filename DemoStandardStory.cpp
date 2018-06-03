#include "OneDimensionalGame.h"
#include "DemoEnemies.h"


void OneDimensionalGame::create_standard_story() {
    add_level(70, StandardMaps::MAP_BLANK);

    DemoEnemies::basic_short(add_prop(0, 2, 10));
    DemoEnemies::basic_long(add_prop(0, 4, 15));

	DemoEnemies::disguise(add_prop(0, 2, 21));
	DemoEnemies::colourful_blue(add_prop(0, 3, 25));

	DemoEnemies::lift(0, 25, 33, 30, this);
	DemoEnemies::trap(0, 5, 62, this);
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

void DemoEnemies::disguise(PassiveEnemy *p) { //why the actual fuck
	p->add_scheme('c', 80, true);
	p->add_scheme('Z', 120, false);  
}

void DemoEnemies::reverse_lift(int level, int size, int location, 
						int speed, OneDimensionalGame* odg) {
	for (int i = 0; i < size; i++) {
		PassiveEnemy *p = odg->add_prop(level, 1, location+i);
		p->add_scheme('R', size*speed + i*speed, false);
		p->add_scheme('G', size*speed - i*speed, true);
	}
}

void DemoEnemies::lift(int level, int size, int location, 
						int speed, OneDimensionalGame* odg) {
	for (int i = 0; i < size; i++) {
		PassiveEnemy *p = odg->add_prop(level, 1, location+i);
		p->add_scheme('G', size*speed + i*speed, true);
		p->add_scheme('R', size*speed - i*speed, false);
	}
}

void DemoEnemies::trap(int level, int size, int location, 
						OneDimensionalGame* odg) {
	if (size <= 2) size=3;  //size should always be > 2

	PassiveEnemy *p1 = odg->add_prop(level, 1, location);
	p1->add_scheme('R', 100, true);
	p1->add_scheme('B', 300, false);
	PassiveEnemy *p2 = odg->add_prop(level, 1, location+size-1);
	p2->add_scheme('R', 100, true);
	p2->add_scheme('B', 300, false);

	for (int i = 1; i < size - 1; i++) {
		PassiveEnemy *p = odg->add_prop(level, 1, location+i);
		p->add_scheme('Z', 100, true);
		p->add_scheme('Z', 300, false);
	}
}