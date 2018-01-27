#include "Prop.h"

Prop::Prop(int location, int size, char* map)
	: location(location), size(size), map(map)
{
	init_default_hitbox();
}

Scheme Prop::create_scheme(char design, int frequency, bool dangerous) {
	Scheme s;
	s.design = design;
	s.frequency = frequency;
	s.dangerous = dangerous;
	return s;
}

void Prop::add_scheme(char design, int frequency, bool dangerous) {
	schemes.push_back(create_scheme(design, frequency, dangerous));
}

bool Prop::within_hitbox(int player_index) {
	return (player_index >= hitbox.start && player_index < hitbox.end);
}

void Prop::init_default_hitbox() {
	hitbox.start = location - 1;
	hitbox.end = location + size - 1;
}