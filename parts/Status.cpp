#pragma once
#include"Status.h"
#include "Item.h"
#include "Tier.h"
Status::Status() {
	agro=-1;
	this->MaxHPDefault=HP=1000;
	damage=100;
	defence=100;
	speed=1.0;
	items=new Item[3];
	setMaxHP();
}
Status::Status(Tier input) {
	items = new Item[3];
	damage = 100;
	defence = 100;
	speed = 1.0;
	for (int i = 0; i < 3; i++) {
		items[i].setType(i);
		items[i].setTier(Tier::getSimillarTier(input.getLevel()));
		items[i].setMyRGB(MyRGB::getMyRGBRandom());
		equipItem(items[i]);
	}
	agro = -1;
	this->MaxHPDefault = 1000;
	setMaxHP();
}
Tier Status::evalTier() {
	Tier temp;
	temp.setLevel((items[0].getTier().getLevel() + items[1].getTier().getLevel() + 
		items[2].getTier().getLevel()) / 3);
	return temp;
}
int	Status::addHP(int input) {
	HP += input;
	if (HP > MaxHP) HP = MaxHP;
	if (HP < 0) HP = 0;
	return 0;
}
int	Status::getHP() {
	return HP;
}
int	Status::addDamage(int input) {
	damage += input;
	return 0;
}
int	Status::getDamage() {
	return damage;
}
void Status::setDamage() {
	damage=this->items[0].getTier().getValue() + damage;
}
int			Status::addDefence(int input) {
	defence += input;
	return 0;
}
int	Status::getDefence() {
	return defence;
}
void Status::setDefence() {
	defence = this->items[1].getTier().getValue() + defence;
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
	MyRGBdamage = (items[0].getMyRGB() + items[2].getMyRGB())*0.5;
	MyRGBdefence = (items[1].getMyRGB() + items[2].getMyRGB())*0.5;
	setMaxHP();
	if(input.getType()==WEAPON)setDamage();
	if (input.getType()==ARMOR)setDefence();
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
int	Status::addMaxHP(int input) {
	MaxHPDefault += input;
	setMaxHP();
	return 0;
}
int	Status::setMaxHP() {
	MaxHP = this->evalTier().getValue() * 10+MaxHPDefault;
	HP = MaxHP;
	return 0;
}
int	Status::getMaxHP() {
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
void Status::initStatus(Tier a) {
	for (int i = 0; i < 3; i++) {
		equipItem(items[i]);
	}

	//////////////////초기화코드
}

void		Status::addMaxHPDefault(int a) {
	this->MaxHPDefault += a;
	setMaxHP();
}
int			Status::getMaxHPDefault() {
	return this->MaxHPDefault;
}
void		Status::setMaxHPDefault(int a) {
	this->MaxHPDefault = a;
	setMaxHP();
}
void		Status::setItemWithNum(Item a, int num) {
	num %= 3;
	this->items[num] = a;
	this->equipItem(a);
}