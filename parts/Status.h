#pragma once
#include "RGB.h"
class Item;
class Tier;
class Status {
private:
	int			agro;
	long long	HP;
	long long	MaxHP;
	long long	damage;
	long long	defence;
	RGB			RGBdamage;
	RGB			RGBdefence;
	float		speed;
	Item		*items; //change to array
public:
	Status();//player
	Status(Tier); //NPC,MONSTER
	long long	setMaxHP();
	long long	addMaxHP(int);
	long long	getMaxHP();
	int			addHP(int);
	long long	getHP();
	int			addDamage(int);
	long long	getDamage();
	int			addDefence(int);
	long long	getDefence();
	RGB			setRGBDamage(RGB);
	RGB			setRGBDefence(RGB);
	int			addRGBDamage(RGB);
	int			addRGBDefence(RGB);
	RGB			getRGBDamage();
	RGB			getRGBDefence();
	float		getSpeed();
	bool		equipItem(Item);
	Tier		evalTier();
};