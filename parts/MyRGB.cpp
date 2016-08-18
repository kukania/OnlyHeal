#pragma once
#include<cstdio>
#include "MyRGB.h"
#include<random>
void MyRGB::ErrorDetector(int v) {
	switch (v) {
	case 0:
		printf("OVERFLOW");
		break;
	case 2:
		printf("UNDERFLOW");
		break;
	}
}
MyRGB::MyRGB() { this->R = this->G = this->B = 0; }
MyRGB::MyRGB(int a, int b, int c) { R = a; G = b; B = c; }
MyRGB MyRGB::operator+ (MyRGB a) {
	MyRGB temp;
	temp.setR(this->R + a.getR());
	temp.setG(this->G + a.getG());
	temp.setB(this->B + a.getB());
	return temp;
}
short MyRGB::checkMyRGBValue(int value) {
	return 1;
}

short MyRGB::setB(short b) {
	int temp = this->checkMyRGBValue(b);
	if (temp == 1) {
		this->B = b;
	}
	return temp;
}
short MyRGB::setG(short b) {
	int temp = this->checkMyRGBValue(b);
	if (temp == 1) {
		this->G = b;
	}return temp;
}
short MyRGB::setR(short b) {
	int temp = this->checkMyRGBValue(b);
	if (temp == 1) {
		this->R = b;
	}return temp;
}
short MyRGB::getR() { return this->R; }
short MyRGB::getG() { return this->G; }
short MyRGB::getB() { return this->B; }
MyRGB MyRGB::getMyRGBRandom() {
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
	MyRGB temp;
	temp.setR((16 - i) * 16 + rand() % 16);
	temp.setG((16 - i) * 16 + rand() % 16);
	temp.setB((16 - i) * 16 + rand() % 16);
	return temp;
}
MyRGB MyRGB::operator*(float input) {
	MyRGB temp;
	temp.setR(this->R*input);
	temp.setG(this->G*input);
	temp.setB(this->B*input);
	return temp;
}