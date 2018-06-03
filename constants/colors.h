#ifndef  COLORS_H_
#define COLORS_H_

#include <stdint.h>

/*============================================================
RGBW NeoPixel permutations; all 4 offsets are distinct
Offset:              W          R          G          B
		  NEO_GRBW ((3 << 6) | (1 << 4) | (0 << 2) | (2))

Takes (uint8_t r, uint8_t g, uint8_t b, uint8_t w)
TEST = ((uint32_t)w << 24) | ((uint32_t)r << 16) | ((uint32_t)g << 8) | b
=============================================================*/

enum color : uint32_t {
	OFF = ((uint32_t)0 << 24) | ((uint32_t)0 << 16) | ((uint32_t)0 << 8) | 0,
	WHITE = ((uint32_t)255 << 24) | ((uint32_t)0 << 16) | ((uint32_t)0 << 8) | 0,

	RED = ((uint32_t)0 << 24) | ((uint32_t)255 << 16) | ((uint32_t)0 << 8) | 0,
	BLUE = ((uint32_t)0 << 24) | ((uint32_t)0 << 16) | ((uint32_t)0 << 8) | 255,
	GREEN = ((uint32_t)0 << 24) | ((uint32_t)0 << 16) | ((uint32_t)255 << 8) | 0,

	PURPLE = ((uint32_t)109 << 24) | ((uint32_t)2 << 16) | ((uint32_t)0 << 8) | 67,
	PLAYER = ((uint32_t)109 << 24) | ((uint32_t)2 << 16) | ((uint32_t)0 << 8) | 67,

	//RGBW(0, 0, 0, 255)
	YELLOW = ((uint32_t)255 << 24) | ((uint32_t)20 << 16) | ((uint32_t)70 << 8) | 0,


	// RGBW(0, 0, 86, 25)
	MIDNIGHT_BLUE = ((uint32_t)25 << 24) | ((uint32_t)0 << 16) | ((uint32_t)0 << 8) | 86,
	// RGBW(0, 40, 190, 65)
	ROYAL_BLUE = ((uint32_t)65 << 24) | ((uint32_t)0 << 16) | ((uint32_t)40 << 8) | 190,
	//RGBW(0, 48, 54, 176)
	POWDER_BLUE = ((uint32_t)176 << 24) | ((uint32_t)0 << 16) | ((uint32_t)48 << 8) | 54,
	// RGBW(115, 0, 0, 140)
	DARK_ORANGE = ((uint32_t)140 << 24) | ((uint32_t)115 << 16) | ((uint32_t)0 << 8) | 0,
	// RGBW(0, 82, 0, 173)
	GREEN_YELLOW = ((uint32_t)160 << 24) | ((uint32_t)0 << 16) | ((uint32_t)82 << 8) | 0,
	PASTEL_GREEN = ((uint32_t)10 << 24) | ((uint32_t)0 << 16) | ((uint32_t)92 << 8) | 40,

	// RGBW(0, 92, 40, 163)
	CYAN = ((uint32_t)5 << 24) | ((uint32_t)0 << 16) | ((uint32_t)92 << 8) | 40,
	EH_GREEN = ((uint32_t)50 << 24) | ((uint32_t)0 << 16) | ((uint32_t)255 << 8) | 0,
	EH_BLUE = ((uint32_t)50 << 24) | ((uint32_t)0 << 16) | ((uint32_t)0 << 8) | 255,

	STUFFLED_GREEN = ((uint32_t)40 << 24) | ((uint32_t)0 << 16) | ((uint32_t)82 << 8) | 0,
	// RGBW(34, 0, 0, 221)
	PASTEL_ORANGE = ((uint32_t)50 << 24) | ((uint32_t)34 << 16) | ((uint32_t)0 << 8) | 0,
	//RGBW(71, 0, 0, 184)
	PASTEL_RED = ((uint32_t)30 << 24) | ((uint32_t)71 << 16) | ((uint32_t)0 << 8) | 0

};


#endif //COLORS_H_