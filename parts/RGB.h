#pragma once
class RGB {
private:
	short R, G, B;
public:
	RGB();
	RGB(int, int, int);
	static RGB getRGBRandom();
	short setR(short);
	short setG(short);
	short setB(short);
	short getR();
	short getG();
	short getB();
	short checkRGBValue(int);
	static void ErrorDetector(int);
	RGB operator+ (RGB a);
	RGB operator*(float);
};