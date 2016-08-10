#pragma once
class RGB {
private:
	int R, G, B;
public:
	RGB();
	int setR(int);
	int setG(int);
	int setB(int);
	int getR();
	int getG();
	int getB();
	bool checkRGBValue(int);
	static void ErrorDetector(int);
};