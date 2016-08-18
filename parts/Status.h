#pragma once
#include "MyRGB.h"
class Item;
class Tier;
class Status {
private:
	int			agro;
	long long	HP;
	long long	MaxHP;
	long long	damage;
	long long	defence;
	MyRGB			MyRGBdamage;
	MyRGB			MyRGBdefence;
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
	int			setAgro(int);
	int			getAgro();
	int			addAgro(int);
	int			setMyRGBDamage(MyRGB);
	int			setMyRGBDefence(MyRGB);
	int			addMyRGBDamage(MyRGB);
	int			addMyRGBDefence(MyRGB);
	int			addSpeed(float);
	MyRGB			getMyRGBDamage();
	MyRGB			getMyRGBDefence();
	float		getSpeed();
	bool		equipItem(Item);
	Tier		evalTier();
};