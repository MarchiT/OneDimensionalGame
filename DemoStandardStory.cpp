#include "OneDimensionalGame.h"
#include "DemoEnemies.h"

//level, size, location, [speed/char], [odg]
void level1(OneDimensionalGame* odg, int level = 0) {
    odg->add_level(StandardMaps::MAP_BLANK);

    DemoEnemies::basic_short(odg->add_passive_enemy(0, 2, 15));
    DemoEnemies::basic_long(odg->add_passive_enemy(0, 4, 23));

	DemoEnemies::colourful_blue(odg->add_passive_enemy(0, 3, 43));
	DemoEnemies::colourful_contrast(odg->add_passive_enemy(0, 3, 50));
	DemoEnemies::disguise(odg->add_passive_enemy(0, 2, 60), StandardMaps::MAP_BLANK[60]);
	DemoEnemies::disguise(odg->add_passive_enemy(0, 2, 65), StandardMaps::MAP_BLANK[65]);
	DemoEnemies::disguise(odg->add_passive_enemy(0, 2, 70), StandardMaps::MAP_BLANK[70]);

	DemoEnemies::reverse_lift(0, 25, 87, 30, odg);
	// DemoEnemies::trap(0, 5, 90, odg);
}

void level2(OneDimensionalGame* odg, int level = 1) {
	odg->add_level(StandardMaps::MAP_BLANK, 83);

	odg->add_item(level, 15);

    DemoEnemies::lock(odg->add_locked_enemy(level, 5, 40));
    DemoEnemies::lock(odg->add_locked_enemy(level, 5, 52));
    DemoEnemies::lock(odg->add_locked_enemy(level, 5, 64));
	
}

void level3(OneDimensionalGame* odg, int level = 2) {
	odg->add_level(StandardMaps::MAP_BLUE_TO_GREEN);

	odg->add_rush_enemy(level);
}

void OneDimensionalGame::create_standard_story() {
	level1(this);
	level2(this);
	level3(this);
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
	p->add_scheme('h', 60, false);
	p->add_scheme('f', 60, false);
	p->add_scheme('B', 60, false);
	p->add_scheme('R', 60, true);
}

void DemoEnemies::colourful_contrast(PassiveEnemy *p) {
	p->add_scheme('m', 60, false);
	p->add_scheme('a', 60, false);
	p->add_scheme('c', 60, false);
	p->add_scheme('G', 180, true);
}

void DemoEnemies::disguise(PassiveEnemy *p, char background) {
	p->add_scheme('c', 80, true);
	p->add_scheme(background, 120, false);  
}

void DemoEnemies::reverse_lift(int level, int size, int location, 
						int speed, OneDimensionalGame* odg) {
	for (int i = 0; i < size; i++) {
		PassiveEnemy *p = odg->add_passive_enemy(level, 1, location+i);
		p->add_scheme('G', size*speed + i*speed, false);
		p->add_scheme('R', size*speed - i*speed, true);
	}
}

void DemoEnemies::lift(int level, int size, int location, 
						int speed, OneDimensionalGame* odg) {
	for (int i = 0; i < size; i++) {
		PassiveEnemy *p = odg->add_passive_enemy(level, 1, location+i);
		p->add_scheme('R', size*speed - i*speed, true);
		p->add_scheme('G', size*speed + i*speed, false);
	}
}

void DemoEnemies::trap(int level, int size, int location, 
						OneDimensionalGame* odg) {
	if (size <= 2) size=3;  //size should always be > 2

	PassiveEnemy *p1 = odg->add_passive_enemy(level, 1, location);
	p1->add_scheme('R', 100, true);
	p1->add_scheme('B', 300, false);
	PassiveEnemy *p2 = odg->add_passive_enemy(level, 1, location+size-1);
	p2->add_scheme('R', 100, true);
	p2->add_scheme('B', 300, false);

	for (int i = 1; i < size - 1; i++) {
		PassiveEnemy *p = odg->add_passive_enemy(level, 1, location+i);
		p->add_scheme('Z', 100, true);
		p->add_scheme('Z', 300, false);
	}
}

void DemoEnemies::lock(LockedEnemy *l) {
	l->add_scheme('W', 60, true);
	l->add_scheme('B', 60, false);
}
