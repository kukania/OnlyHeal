#pragma once
class RGB {
private:
	short R, G, B;
public:
	RGB();
	short setRGBRandom(int ,int);
	short setR(short);
	short setG(short);
	short setB(short);
	short getR();
	short getG();
	short getB();
	short checkRGBValue(int);
	static void ErrorDetector(int);
};