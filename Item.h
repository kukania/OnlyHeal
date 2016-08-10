#pragma once
#include <string>
#include "RGB.h"
using namespace std;

class Item {
public:
	string	tier;
	int		type;
	int		value;
	RGB		rgb;

	Item();
	Item(string, int, RGB);

	void setTier(string);
	void setType(int);
	void setValue(string);
	void setRGB(RGB);

	string	getTier();
	int		getType();
	int		getValue();
	RGB		getRGB();
};