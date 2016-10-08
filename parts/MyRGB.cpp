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
MyRGB::MyRGB(ColorType type, float value) {
	this->type = type;
	this->value = value;
	MyRGB temp = MyRGB::ColorTypeToRGB(type, value);
	this->setR(temp.getR());
	this->setG(temp.getG());
	this->setB(temp.getB());
}
MyRGB MyRGB::operator+ (MyRGB a) {
	MyRGB temp;
	temp.setR(this->R + a.getR());
	temp.setG(this->G + a.getG());
	temp.setB(this->B + a.getB());
	return temp;
}
short MyRGB::checkMyRGBValue(int value) {
	if (value > 255)
		return 0;
	else if (value < 0)
		return 2;
	return 1;
}
short MyRGB::setB(short b) {
	int temp = this->checkMyRGBValue(b);
	if (temp == 1) {
		this->B = b;
	}
	else if (temp == 0) {
		this->B = 255;
	}
	else {
		this->B = 0;
	}
	return temp;
}
short MyRGB::setG(short b) {
	int temp = this->checkMyRGBValue(b);
	if (temp == 1) {
		this->G = b;
	}
	else if (temp == 0) {
		this->G = 255;
	}
	else {
		this->G = 0;
	}
	return temp;
}
short MyRGB::setR(short b) {
	int temp = this->checkMyRGBValue(b);
	if (temp == 1) {
		this->R = b;
	}
	else if (temp == 0) {
		this->R = 255;
	}
	else {
		this->R = 0;
	}
	return temp;
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
MyRGB MyRGB::getMyRGBRandom(float value) {
	return MyRGB::ColorTypeToRGB((MyRGB::ColorType)(rand()%12),value);
}
MyRGB MyRGB::getMyRGBRandom(ColorType t) {
	return MyRGB::ColorTypeToRGB(t, (rand()%4+1)*0.25);
}
MyRGB MyRGB::ColorTypeToRGB(ColorType t, float value) {
	MyRGB res;
	switch (t)
	{
	case MyRGB::RED:
		res = MyRGB::HSL2RGB((float)0, value, 0.5);
		break;
	case MyRGB::LIME:
		res = MyRGB::HSL2RGB(1.0f/3.0f, value, 0.5);
		break;
	case MyRGB::BLUE:
		res = MyRGB::HSL2RGB(2.0f/3.0f, value, 0.5);
		break;
	case MyRGB::YELLOW:
		res = MyRGB::HSL2RGB(1.0f/6.0f, value, 0.5);
		break;
	case MyRGB::CYAN:
		res = MyRGB::HSL2RGB(1.0f/2.0f, value, 0.5);
		break;
	case MyRGB::MAGENTA:
		res = MyRGB::HSL2RGB(5.0f/6.0f, value, 0.5);
		break;
	case MyRGB::MAROON:
		res = MyRGB::HSL2RGB(0, value, 0.25);
		break;
	case MyRGB::OLIVE:
		res = MyRGB::HSL2RGB(1.0f/6.0f, value, 0.25);
		break;
	case MyRGB::GREEN:
		res = MyRGB::HSL2RGB(1.0f/3.0f, value, 0.25);
		break;
	case MyRGB::PURPLE:
		res = MyRGB::HSL2RGB(5.0f/6.0f, value, 0.25);
		break;
	case MyRGB::TEAL:
		res = MyRGB::HSL2RGB(1.0f/2.0f, value, 0.25);
		break;
	case MyRGB::NAVY:
		res = MyRGB::HSL2RGB(2.0f/3.0f, value, 0.25);
		break;
	}
	res.type = t;
	res.value = value;
	return res;
}
MyRGB MyRGB::HSL2RGB(float h, float s, float l) {
	int r, g, b;
	if (s == 0) {
		r = g = b = (int)(l * 255);
	}
	else {
		float var2, var1;
		if (l < 0.5f) var2 = l*(1 + s);
		else var2 = (l + s) - (s*l);
		var1 = 2 * l - var2;
	
		r = (int)(255 * Hue2RGB(var1, var2, h + (1.0f / 3.0f)));
		g= (int)(255 * Hue2RGB(var1, var2, h ));
		b= (int)(255 * Hue2RGB(var1, var2, h-(1.0f/3.0f)));
	}
	return MyRGB(r, g, b);
}
float MyRGB::Hue2RGB(float v1, float v2, float vH) {
	if (vH < 0) vH += 1;
	else if (vH > 1)vH -= 1;
	if ((6 * vH) < 1)return (v1 + (v2 - v1) * 6 * vH);
	if ((2 * vH) < 1)return v2;
	if ((3 * vH) < 2) return(v1 + (v2 - v1)*((2.0f / 3.0f - vH)) * 6);
	return v1;
}
MyRGB MyRGB::operator*(float input) {
	MyRGB temp;
	temp.setR(this->R*input);
	temp.setG(this->G*input);
	temp.setB(this->B*input);
	return temp;
}