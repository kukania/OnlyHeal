#pragma once
#include "RGB.h"
class Item;
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
	Status(Teir); //NPC,MONSTER
	int			setHP(long long);
	long long	getHP();
	int			setDamage(long long);
	long long	getDamage();
	int			setDefence(long long);
	long long	getDefence();
	int			setRGBDamage(RGB);
	RGB			getRGBDamage();
	int			setRGBDefence(RGB);
	RGB			getRGBDefence();
	int			setSpeed(float);
	long long	getSpeed();
	bool		equipItem(Item);
};