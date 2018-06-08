#include "Prop.h"

Prop::Prop(int location, int size, char* map, int hitbox_start, int hitbox_end)
	: location(location), size(size), map(map)
{
	if (hitbox_start == hitbox_end) {
		hitbox_start = location - 1;
		hitbox_end = hitbox_start + size;
	}
	set_hitbox(hitbox_start, hitbox_end);
}

Scheme Prop::create_scheme(char design, int loops, bool interact) {
	Scheme s;
	s.design = design;
	s.loops = loops;
	s.interact = interact;
	return s;
}

void Prop::add_scheme(char design, int loops, bool interact) {
	schemes.push_back(create_scheme(design, loops, interact));
}

bool Prop::remove_schemes() {
	// schemes.erase(std::remove(schemes.begin(), schemes.end(), to_remove), schemes.end());
	// schemes.erase(std::find(schemes.begin(), schemes.end(), to_remove));
	schemes.clear();
}

bool Prop::within_hitbox(int player_index) {
	return (player_index >= hitbox.start && player_index < hitbox.end);
}

void Prop::set_hitbox(int start, int end) {
	if (end < start) {int temp = start; start = end; end = temp;}
	hitbox.start = start;
	hitbox.end = end;
}

void Prop::draw() {
	if (++state < schemes[index].loops) {
		for (int i = location - 1; i < location + size - 1; i++) {
			map[i] = schemes[index].design;
		}
	} else {
		state = 0;
		if (++index == schemes.size()) index = 0;
	}
}