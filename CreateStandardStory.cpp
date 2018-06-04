#include "OneDimensionalGame.h"

//add_level(7); //size, [map]
//add_passive_enemys(0, 3, 3); //level, size, location

void basic_enemy(PassiveEnemy *p) {
	p->add_scheme('G', 70, false);
	p->add_scheme('R', 100, true);  
}

void long_enemy(PassiveEnemy *p) {
	p->add_scheme('G', 140, false);
	p->add_scheme('R', 70, true);  
}

int busy = 0;
void stoplight_enemy(PassiveEnemy *p) {
	p->add_scheme('R', 95, false);
	p->add_scheme('Y', 50, busy == true ? busy-- : busy++); //add real YELLOW
	p->add_scheme('G', 85, true);  
}

void colour_enemy_blue(PassiveEnemy *p) {
	p->add_scheme('f', 50, false);
	p->add_scheme('h', 50, false);
	p->add_scheme('B', 50, false);
	p->add_scheme('R', 70, true);  //MAKE RED MORE SHINY
}

void red_colour_enemy_red(PassiveEnemy *p) {
	p->add_scheme('c', 50, true); //GHANGE THE REDS
	p->add_scheme('b', 40, true);
	p->add_scheme('i', 30, true);
	p->add_scheme('G', 70, false);
}

void disguise_enemy(PassiveEnemy *p, char colour) {
	p->add_scheme('c', 70, false);
	p->add_scheme(colour, 90, true);  
}

char switch_colour(char prev, char next, char ch) {
	ch = ch == prev ? next : prev;
}

void polka_switch_enemy(int level, int size, int location, OneDimensionalGame* odg) {
	if (size % 2 == 0) size++;  //size should always be an odd number
	bool sw = false;

	for (int i = 0; i < size; i++) {
		PassiveEnemy *p = odg->add_passive_enemy(level, 1, location+i);
		if (!sw) {
			sw = true;
			p->add_scheme('B', 70, true);
			p->add_scheme('c', 70, false);
		} else {
			sw = false;
			p->add_scheme('c', 70, false);
			p->add_scheme('g', 70, false);	
		}
	}
}

void polka_enemy(int level, int size, int location, OneDimensionalGame* odg) {
	if (size % 2 == 0) size++;  //size should always be an odd number
	bool sw = false;

	for (int i = 0; i < size; i++) {
		PassiveEnemy *p = odg->add_passive_enemy(level, 1, location+i);
		if (!sw) {
			sw = true;
			p->add_scheme('B', 70, true);
			p->add_scheme('c', 70, false);
		} else {
			sw = false;
			p->add_scheme('c', 70, false);
			// p->add_scheme('c', 70, true);	
		}
	}
}

void transparent_enemy(int level, int size, int location, OneDimensionalGame* odg) {
	if (size <= 2) size=3;  //size should always be bigger than 2

	PassiveEnemy *p1 = odg->add_passive_enemy(level, 1, location);
	p1->add_scheme('R', 70, true);
	p1->add_scheme('B', 120, false);
	PassiveEnemy *p2 = odg->add_passive_enemy(level, 1, location+size-1);
	p2->add_scheme('R', 70, true);
	p2->add_scheme('B', 120, false);

	for (int i = 1; i < size - 1; i++) {
		PassiveEnemy *p = odg->add_passive_enemy(level, 1, location+i);
		p->add_scheme('Z', 70, true);
		p->add_scheme('Z', 120, true);
	}
}

void steps_enemy(int level, int size, int location, int speed, OneDimensionalGame* odg) {
	bool sw = false;

	for (int i = 0; i < size; i++) {
		PassiveEnemy *p = odg->add_passive_enemy(level, 1, location+i);
		p->add_scheme('c', size*speed + i*speed, false);
		p->add_scheme('G', size*speed - i*speed, true);
	}
}

void chaos_enemy(int level, int location, OneDimensionalGame* odg) {
	//diffuse = 170;
	//size = 4;

	PassiveEnemy *p = odg->add_passive_enemy(level, 1, location);
	p->add_scheme('R', 100, true);
	p->add_scheme('G', 20, true);
	p->add_scheme('B', 50, true);
	p->add_scheme('W', 100, false);

	p = odg->add_passive_enemy(level, 1, location+1);
	p->add_scheme('B', 30, true);
	p->add_scheme('R', 70, true);
	p->add_scheme('G', 70, true);
	p->add_scheme('W', 100, false);

	p = odg->add_passive_enemy(level, 1, location+2);
	p->add_scheme('G', 85, true);
	p->add_scheme('R', 25, true);
	p->add_scheme('B', 60, true);
	p->add_scheme('W', 100, false);

	p = odg->add_passive_enemy(level, 1, location+3);
	p->add_scheme('R', 90, true);
	p->add_scheme('B', 40, true);
	p->add_scheme('G', 40, true);
	p->add_scheme('W', 100, false);
}

void random_enemy(int level, int size, int location, OneDimensionalGame* odg) {
	bool sw = false;

	for (int i = 0; i < size; i++) {
		PassiveEnemy *p = odg->add_passive_enemy(level, 1, location+i);
		p->add_scheme('G', 70 + i*20, true);
		p->add_scheme('c', 70 + i*20, false);
	}
}

// void OneDimensionalGame::create_standard_story() {

// 	add_level(NUM_LEDS, StandardStory::MAP_TEST);
//     //simple enemies segment
//     basic_enemy(add_passive_enemy(0, 2, 13));
//     basic_enemy(add_passive_enemy(0, 2, 18));
//     long_enemy(add_passive_enemy(0, 5, 25));
//     stoplight_enemy(add_passive_enemy(0, 3, 35));
//     colour_enemy_blue(add_passive_enemy(0, 5, 41));
// 	red_colour_enemy_red(add_passive_enemy(0, 3, 51));
// 	red_colour_enemy_red(add_passive_enemy(0, 2, 58));
// 	//red segment simple
// 	disguise_enemy(add_passive_enemy(0, 4, 64), 'B');
// 	disguise_enemy(add_passive_enemy(0, 2, 70), 'G');
// 	disguise_enemy(add_passive_enemy(0, 1, 73), 'R');
	
// 	//red segment collective
// 	// polka_enemy(0, 5, 79, this);
// 	polka_switch_enemy(0, 5, 77, this);
// 	transparent_enemy(0, 4, 85, this);
// 	steps_enemy(0, 7, 94, 20, this);
// 	chaos_enemy(0, 104, this);
// }
