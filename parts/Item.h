#pragma once
#include <string>
#include "MyRGB.h"
#include "Tier.h"
using namespace std;
enum ItemEnum {
	WEAPON, ARMOR, ARTIFACT
};
class Item {
public:
	Tier	tier;
	int		type;
	MyRGB	rgb;
	bool	isNew;
	Item();
	Item(Tier, int, MyRGB);
	void	setTier(Tier);
	void	setType(int);
	void	setMyRGB(MyRGB);
	Tier	getTier();
	int		getType();
	MyRGB	getMyRGB();
	string  toString();
};