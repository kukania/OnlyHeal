#pragma once
#include <string>
#include "MyRGB.h"
#include "Tier.h"
using namespace std;

class Item {
public:
	enum TYPE {
		WEAPON,ARMOR,ARTIFACT
	};
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
	std::string  toString();
	std::string  getFileString();/*FTYPE tier type rgb isNew*/
	static Item itemByString(std::string fstring[]);
};