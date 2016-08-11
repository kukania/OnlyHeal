#pragma once
#include "RGB.h"
class Item;
class Tier;
class Status {
private:
	int			agro;
	long long	HP;
	long long	damage;
	long long	defence;
	RGB			RGBdamage;
	RGB			RGBdefence;
	float		speed;
	Item		*items; //change to array
public:
	Status();//player
	Status(Tier); //NPC,MONSTER
	int			addHP(int);
	long long	getHP();
	int			addDamage(int);
	long long	getDamage();
	int			addDefence(int);
	long long	getDefence();
	RGB			getRGBDamage();
	RGB			getRGBDefence();
	float		getSpeed();
	bool		equipItem(Item);
	Tier		evalTier();
};