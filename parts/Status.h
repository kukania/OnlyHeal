#pragma once
#include "MyRGB.h"
class Item;
class Tier;
class Status {
private:
	int			agro;
	int	HP;
	int	MaxHP;
	int	damage;
	int	defence;
	MyRGB			MyRGBdamage;
	MyRGB			MyRGBdefence;
	float		speed;
	Item		*items; //change to array
public:
	Status();//player
	Status(Tier); //NPC,MONSTER
	int	setMaxHP();
	int	addMaxHP(int);
	int	getMaxHP();
	int			addHP(int);
	int	getHP();
	int			addDamage(int);
	int	getDamage();
	int			addDefence(int);
	int	getDefence();
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