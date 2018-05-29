#include "OneDimensionalGame.h"


void basic_enemy(PassiveEnemy *p) {
	p->add_scheme('G', 70, false);
	p->add_scheme('R', 100, true);  
}

void long_enemy(PassiveEnemy *p) {
	p->add_scheme('G', 140, false);
	p->add_scheme('R', 70, true);  
}

void color_enemy(PassiveEnemy *p) {
	p->add_scheme('f', 50, false);
	p->add_scheme('h', 50, false);
	p->add_scheme('i', 50, false);
	p->add_scheme('R', 70, true);  
}

void disguise_enemy(PassiveEnemy *p) {
	p->add_scheme('b', 70, false);
	p->add_scheme('B', 90, true);  
}

void OneDimensionalGame::create_standard_story() {
	//add_level(7); //size, [map]
	//add_props(0, 3, 3); //level, size, location

	add_level(144, StandardStory::MAP1);
    // //disguise enemies: texture-prev_texture
	disguise_enemy(add_prop(0, 3, 131)); 
	disguise_enemy(add_prop(0, 2, 138)); 
    // //basic enemies
    basic_enemy(add_prop(0, 2, 8));
    basic_enemy(add_prop(0, 2, 26));
    long_enemy(add_prop(0, 4, 33));
    long_enemy(add_prop(0, 5, 43));
    color_enemy(add_prop(0, 3, 68));
    color_enemy(add_prop(0, 3, 78));
	

	add_level(144, StandardStory::MAP2);
	// add_props(1, 4, 15);
	// //134
	// basic_enemy(add_prop(1, 2, 7));
	// basic_enemy(add_prop(1, 2, 11));
	// basic_enemy(add_prop(1, 2, 15));

	// basic_enemy(add_prop(1, 3, 20));
	// basic_enemy(add_prop(1, 3, 25));

	// basic_enemy(add_prop(1, 2, 31));
	// basic_enemy(add_prop(1, 2, 35));
	// basic_enemy(add_prop(1, 2, 39));

	// long_enemy(add_prop(1, 5, 46));

	// color_enemy(add_prop(1, 2, 56));
	// basic_enemy(add_prop(1, 2, 60));
	// color_enemy(add_prop(1, 3, 64));
	// basic_enemy(add_prop(1, 2, 69));
	// color_enemy(add_prop(1, 2, 73));

	
	// long_enemy(add_prop(1, 5, 93));

	// disguise_enemy(add_prop(1, 3, 102)); 
	// disguise_enemy(add_prop(1, 3, 107));

	// long_enemy(add_prop(1, 4, 114));	 
	
}
