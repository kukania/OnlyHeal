#pragma once
class MyRGB {
private:
	short R, G, B;
public:
	MyRGB();
	MyRGB(int, int, int);
	static MyRGB getMyRGBRandom();
	short setR(short);
	short setG(short);
	short setB(short);
	short getR();
	short getG();
	short getB();
	short checkMyRGBValue(int);
	static void ErrorDetector(int);
	MyRGB operator+ (MyRGB a);
	MyRGB operator*(float);
};