#pragma once
#include<cstdio>
#include "RGB.h"
#include<random>
void RGB::ErrorDetector(int v) {
	switch (v) {
	case 0:
		printf("OVERFLOW");
		break;
	case 2:
		printf("UNDERFLOW");
		break;
	}
}
RGB::RGB() { this->R = this->G = this->B = 0; }
RGB::RGB(int a, int b, int c) { R = a; G = b; B = c; }
RGB RGB::operator+ (RGB a) {
	RGB temp;
	temp.setR(this->R + a.getR());
	temp.setG(this->G + a.getG());
	temp.setB(this->B + a.getB());
	return temp;
}
short RGB::checkRGBValue(int value) {
	return 1;
}

short RGB::setB(short b) {
	int temp = this->checkRGBValue(b);
	if (temp == 1) {
		this->B = b;
	}
	return temp;
}
short RGB::setG(short b) {
	int temp = this->checkRGBValue(b);
	if (temp == 1) {
		this->G = b;
	}return temp;
}
short RGB::setR(short b) {
	int temp = this->checkRGBValue(b);
	if (temp == 1) {
		this->R = b;
	}return temp;
}
short RGB::getR() { return this->R; }
short RGB::getG() { return this->G; }
short RGB::getB() { return this->B; }
RGB RGB::getRGBRandom() {
	int arr[17],i;
	arr[0] = 0;
	for (i = 1; i <=16; i++) {
		arr[i] = arr[i -1] +  i;
	}
	int value = rand() % 136+1;
	for (i = 1; i <=16; i++) {
		if (value <=arr[i])
			break;
	}
	RGB temp;
	temp.setR((16 - i) * 16 + rand() % 16);
	temp.setG((16 - i) * 16 + rand() % 16);
	temp.setB((16 - i) * 16 + rand() % 16);
	return temp;
}