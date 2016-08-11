#pragma once
#include"Status.h"
#include "Item.h"
#include "Tier.h"
Status::Status() {
	agro=-1;
	HP=1000;
	damage=100;
	defence=100;
	speed=1.0;
	items=new Item[3];
}
Status::Status(Tier input) {
	for (int i = 0; i < 3; i++) {
		items[i].setType(i);
		items[i].setTier(Tier::getSimillarTier(input.getLevel()));
	}
	agro = -1;
	items = new Item[3];
	
	damage = items[0].getTier().getValue() + 100;
	defence = items[1].getTier().getValue() + 100;
	speed = 1.0;
}
Tier Status::evalTier() {
	Tier temp;
	temp.setLevel((items[0].getTier().getLevel() + items[1].getTier().getLevel() + 
		items[2].getTier().getLevel()) / 3+(damage - 100 + defence - 100)/10);
	return temp;
}
int	Status::setHP() {
	HP = this->evalTier().getValue() + 1000;
}
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