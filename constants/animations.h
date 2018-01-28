#ifndef ANIMATIONS_H_
#define ANIMATIONS_H_

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif


class Animations {
public:

	static void rainbowFade2White(Adafruit_NeoPixel strip, uint8_t wait, int rainbowLoops, int whiteLoops) {
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
		
		float fadeMax = 100.0;
		int fadeVal = 0;
		uint32_t wheelVal;
		int redVal, greenVal, blueVal;

		for (int k = 0; k < rainbowLoops; k++) {
			for (int j = 0; j<256; j++) { // 5 cycles of all colors on wheel
				for (int i = 0; i< strip.numPixels(); i++) {
					wheelVal = Wheel(strip, ((i * 256 / strip.numPixels()) + j) & 255);

					redVal = red(wheelVal) * float(fadeVal / fadeMax);
					greenVal = green(wheelVal) * float(fadeVal / fadeMax);
					blueVal = blue(wheelVal) * float(fadeVal / fadeMax);

					strip.setPixelColor(i, strip.Color(redVal, greenVal, blueVal));
				}

				//First loop, fade in!
				if (k == 0 && fadeVal < fadeMax - 1) {
					fadeVal++;
				}
				//Last loop, fade out!
				else if (k == rainbowLoops - 1 && j > 255 - fadeMax) {
					fadeVal--;
				}

				strip.show();
				Sleep(wait);
			}

		}

		Sleep(500);

		for (int k = 0; k < whiteLoops; k++) {
			for (int j = 0; j < 256; j++) {

				for (uint16_t i = 0; i < strip.numPixels(); i++) {
					strip.setPixelColor(i, strip.Color(0, 0, 0, neopix_gamma[j]));
				}
				strip.show();
			}
			Sleep(2000);
			for (int j = 255; j >= 0; j--) {

				for (uint16_t i = 0; i < strip.numPixels(); i++) {
					strip.setPixelColor(i, strip.Color(0, 0, 0, neopix_gamma[j]));
				}
				strip.show();
			}
		}
		Sleep(500);
	}

	static uint8_t red(uint32_t c) {
		return (c >> 16);
	}
	static uint8_t green(uint32_t c) {
		return (c >> 8);
	}
	static uint8_t blue(uint32_t c) {
		return (c);
	}

	static uint32_t Wheel(Adafruit_NeoPixel strip, byte WheelPos) {
		WheelPos = 255 - WheelPos;
		if (WheelPos < 85) {
			return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3, 0);
		}
		if (WheelPos < 170) {
			WheelPos -= 85;
			return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3, 0);
		}
		WheelPos -= 170;
		return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0, 0);
	}
};

#endif //ANIMATIONS_H_