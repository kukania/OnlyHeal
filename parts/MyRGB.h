#pragma once
class MyRGB {

public:
	enum ColorType{
		RED,LIME,BLUE,YELLOW,CYAN,MAGENTA,MAROON,OLIVE,GREEN,PURPLE,TEAL,NAVY
	};
	MyRGB();
	MyRGB(int, int, int);
	MyRGB(ColorType, float value);
	static MyRGB getMyRGBRandom();
	static MyRGB getMyRGBRandom(float value);
	static MyRGB getMyRGBRandom(ColorType);
	short setR(short);
	short setG(short);
	short setB(short);
	short getR();
	short getG();
	short getB();
	short checkMyRGBValue(int);
	static void ErrorDetector(int);
	static MyRGB ColorTypeToRGB(ColorType, float value);
	static MyRGB HSL2RGB(float h, float s, float l);
	MyRGB operator+ (MyRGB a);
	MyRGB operator*(float);
	ColorType type;
	float value;
private:
	static float Hue2RGB(float, float, float);
	short R, G, B;
};