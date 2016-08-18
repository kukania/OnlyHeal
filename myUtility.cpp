#include "myUtility.h"

// debug function
bool isRange(char *an, int a, int max, int min) {
	if (a < min) {
		printf("[%s: %d] is little than MIN: %d\n", an, a, min);
		return false;
	}
	if (a > max) {
		printf("[%s: %d] is larger than MAX: %d\n", an, a, max);
		return false;
	}
	return true;
}

float calcMyRGB(MyRGB rgb1, MyRGB rgb2) {
	int a = rgb1.getR() - rgb2.getR();
	if (a < 0) a = 0;
	int b = rgb1.getG() - rgb2.getG();
	if (b < 0) b = 0;
	int c = rgb1.getB() - rgb2.getB();
	if (c < 0) c = 0;
	return (a + b + c) / (3 * 255);
}