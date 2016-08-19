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
		items[i].setMyRGB(MyRGB::getMyRGBRandom());
		equipItem(items[i]);
	}
	agro = -1;
	this->MaxHP=HP = 1000;
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
MyRGB			Status::getMyRGBDamage() {
	return MyRGBdamage;
}
int			Status::setMyRGBDamage(MyRGB input) {
	MyRGBdamage = input;
	return true;
}
int			Status::setMyRGBDefence(MyRGB input) {
	MyRGBdefence = input;
	return true;
}
MyRGB			Status::getMyRGBDefence() {
	return MyRGBdefence;
}
float 		Status::getSpeed() {
	return this->items[2].getTier().getValue() / 10000 + speed;
}
int			Status::addSpeed(float in) {
	speed += in;
	return 0;
}
bool		Status::equipItem(Item input) {
	items[input.getType()] = input;
	MyRGBdamage = items[0].getMyRGB() + items[2].getMyRGB();
	MyRGBdefence = items[1].getMyRGB() + items[2].getMyRGB();
	return 0;
}
int			Status::addMyRGBDamage(MyRGB input) {
	MyRGBdamage = MyRGBdamage + input;
	return 0;
}
int			Status::addMyRGBDefence(MyRGB input) {
	MyRGBdefence = input + MyRGBdefence;
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
int			Status::setAgro(int input) {
	agro = input;
	return 0;
}
int			Status::getAgro() {
	return agro;
}
int			Status::addAgro(int input) {
	agro += input;
	return 0;
}