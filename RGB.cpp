#pragma once
#include<cstdio>
#include "RGB.h"
void RGB::ErrorDetector(int v) {
	switch (v) {
	case 0:
		printf("OVERFLOW");
		break;
	case 1:
		printf("UNDERFLOW");
		break;
	}
}
RGB::RGB() { this->R = this->G = this->B = 0; }
int RGB::setB(int b) { this->B = b; }
int RGB::setG(int g) { this->G = g; }
int RGB::setR(int r) { this->R = r; }
int RGB::getR() { return this->R; }
int RGB::getG() { return this->G; }
int RGB::getB() { return this->B; }