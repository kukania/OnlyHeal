#pragma once
#include <string>
#include "RGB.h"
#include "Tier.h"
using namespace std;

class Item {
public:
	Tier	tier;
	int		type;
	RGB		rgb;

	Item();
	Item(Tier, int, RGB);

	void setTier(Tier);
	void setType(int);
	void setRGB(RGB);

	Tier	getTier();
	int		getType();
	RGB		getRGB();
};