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
short RGB::checkRGBValue(int value) {
	if (value < 0) return 2;
	else if (value > 255) return 0;
	else return 1;
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
		this->B = b;
	}return temp;
}
short RGB::setR(short b) {
	int temp = this->checkRGBValue(b);
	if (temp == 1) {
		this->B = b;
	}return temp;
}
short RGB::getR() { return this->R; }
short RGB::getG() { return this->G; }
short RGB::getB() { return this->B; }
short RGB::setRGBRandom(int max=256, int min = 1) {
	this->R = rand() % max + min;
	this->G = rand() % max + min;
	this->B = rand() % max + min;
}