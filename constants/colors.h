#ifndef  COLORS_H_
#define COLORS_H_

#include <stdint.h>

// RGBW NeoPixel permutations; all 4 offsets are distinct
// Offset:           W          R          G          B
//		  NEO_GRBW ((3 << 6) | (1 << 4) | (0 << 2) | (2))

enum color : uint32_t {
	OFF = ((uint32_t)0 << 24) | ((uint32_t)0 << 16) | ((uint32_t)0 << 8) | 0,
	WHITE = ((uint32_t)255 << 24) | ((uint32_t)0 << 16) | ((uint32_t)0 << 8) | 0,

	RED = ((uint32_t)0 << 24) | ((uint32_t)255 << 16) | ((uint32_t)0 << 8) | 0,
	BLUE = ((uint32_t)0 << 24) | ((uint32_t)0 << 16) | ((uint32_t)0 << 8) | 255,
	GREEN = ((uint32_t)0 << 24) | ((uint32_t)0 << 16) | ((uint32_t)255 << 8) | 0,

	PURPLE = ((uint32_t)109 << 24) | ((uint32_t)2 << 16) | ((uint32_t)0 << 8) | 67,
	PLAYER = ((uint32_t)109 << 24) | ((uint32_t)2 << 16) | ((uint32_t)0 << 8) | 67

	//Takes (uint8_t r, uint8_t g, uint8_t b, uint8_t w)
	//TEST = ((uint32_t)w << 24) | ((uint32_t)r << 16) | ((uint32_t)g << 8) | b
};


#endif //COLORS_H_