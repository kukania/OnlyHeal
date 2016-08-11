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
	items = new Item[3];
	for (int i = 0; i < 3; i++) {
		items[i].setType(i);
		items[i].setTier(Tier::getSimillarTier(input.getLevel()));
		equipItem(items[i]);
	}
	agro = -1;
	HP = 1000;
	damage =  100;
	defence = 100;
	speed = 1.0;
}
Tier Status::evalTier() {
	Tier temp;
	temp.setLevel((items[0].getTier().getLevel() + items[1].getTier().getLevel() + 
		items[2].getTier().getLevel()) / 3+(damage - 100 + defence - 100)/10);
	return temp;
}
int	Status::addHP(int input) {
	HP += input;
	if (HP > MaxHP) HP = MaxHP;
	if (HP < 0) HP = 0;
	return 0;
}
long long	Status::getHP() {
	return HP;
}
int	Status::addDamage(int input) {
	damage += input;
	return 0;
}
long long	Status::getDamage() {
	return this->items[0].getTier().getValue() + damage;
}
int			Status::addDefence(int input) {
	defence += input;
	return 0;
}
long long	Status::getDefence() {
	return this->items[1].getTier().getValue() + defence;
}
RGB			Status::getRGBDamage() {
	return RGBdamage;
}
RGB			Status::setRGBDamage(RGB input) {
	RGBdamage = input;
}
RGB			Status::setRGBDefence(RGB input) {
	RGBdefence = input;
}
RGB			Status::getRGBDefence() {
	return RGBdefence;
}
float 		Status::getSpeed() {
	return this->items[2].getTier().getValue() / 10000 + speed;
}
bool		Status::equipItem(Item input) {
	items[input.getType()] = input;
	RGBdamage = items[0].getRGB() + items[2].getRGB;
	RGBdefence = items[1].getRGB() + items[2].getRGB;
	return 0;
}
int			Status::addRGBDamage(RGB input) {
	RGBdamage = RGBdamage + input;
	return 0;
}
int			Status::addRGBDefence(RGB input) {
	RGBdefence = input + RGBdefence;
	return 0;
}
long long	Status::addMaxHP(int input) {
	MaxHP += input;
	setMaxHP();
	return 0;
}
long long	Status::setMaxHP() {
	MaxHP = this->evalTier().getValue() * 10+MaxHP;
	return 0;
}
long long	Status::getMaxHP() {
	return MaxHP;
}