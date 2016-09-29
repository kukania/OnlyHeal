#pragma once
#include "MyRGB.h"

class Item;
class Tier;
class Status {
private:
	int			agro;
	int			HP;
	int			MaxHP;
	int			MaxHPDefault; //pureMHP
	int			damage;
	int			defence;
	int			pureDamage;
	int			pureDefence;
	MyRGB		MyRGBdamage;
	MyRGB		MyRGBdefence;
	float		speed;
	Item		*items; //change to array
public:
	Status();//player
	Status(Tier); //NPC,MONSTER
	void		initStatus(Tier);
	int			setMaxHP();
	int			getMaxHP();
	int			addHP(int);
	int			getHP();
	int			addDamage(int);
	void		setDamage();
	int			getDamage();
	int			addDefence(int);
	void		setDefence();
	int			getDefence();
	int			setAgro(int);
	int			getAgro();
	int			addAgro(int);
	int			setMyRGBDamage(MyRGB);
	int			setMyRGBDefence(MyRGB);
	int			addMyRGBDamage(MyRGB);
	int			addMyRGBDefence(MyRGB);
	int			addSpeed(float);
	MyRGB		getMyRGBDamage();
	MyRGB		getMyRGBDefence();
	float		getSpeed();
	bool		equipItem(Item);
	Tier		evalTier();
	void		addMaxHPDefault(int);
	int			getMaxHPDefault();
	void		setMaxHPDefault(int);
	void		setItemWithNum(Item, int);
};