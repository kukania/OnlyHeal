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
	int			setHP();
	long long	getHP();
	int			setDamage();
	long long	getDamage();
	int			setDefence();
	long long	getDefence();
	int			setRGBDamage();
	RGB			getRGBDamage();
	int			setRGBDefence();
	RGB			getRGBDefence();
	int			setSpeed();
	long long	getSpeed();
	bool		equipItem(Item);
	Tier		evalTier();
};