#pragma once
#include <string>
#include "MyRGB.h"
#include "Tier.h"
using namespace std;

class Item {
public:
	Tier	tier;
	int		type;
	MyRGB	rgb;
	Item();
	Item(Tier, int, MyRGB);
	void	setTier(Tier);
	void	setType(int);
	void	setMyRGB(MyRGB);
	Tier	getTier();
	int		getType();
	MyRGB	getMyRGB();
};