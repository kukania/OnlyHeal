/*
FileName:	Character.cpp
Revision:	? by Kukania
Modified:	2016/09/07 by PorcaM
*/

#pragma once
#include "Character.h"
#include "MeleeNPC.h"
#include "TankNPC.h"
#include "RangeNPC.h"
#include "Monster.h"
#include"cocos2d.h"
#include<string>
#include <cstdio>
//user
#include <random>

Character* Character::create(Tier t, const char* input, int index) {
	std::string typeOfChar = input;
	Character *myCharacter = nullptr;
	if (typeOfChar.compare("User") == 0) {
		//user
	}
	else if (typeOfChar.compare("MeleeNPC") == 0) {
		myCharacter = new MeleeNPC(t);
		myCharacter->setType(melee);
	}
	else if (typeOfChar.compare("Monster") == 0) {
		myCharacter = new Monster(t);
		myCharacter->setType(monster);
	}
	else if (typeOfChar.compare("RangeNPC") == 0) {
		myCharacter = new RangeNPC(t);
		myCharacter->setType(range);
	}
	else if (typeOfChar.compare("TankNPC") == 0) {
		myCharacter = new TankNPC(t);
		myCharacter->setType(tanker);
	}
	myCharacter->setIndex(index);
	return myCharacter;
}
int Character::beAttacked(int damage) {
	myStatus.addHP(-damage);
	this->attackedDamage.push(damage);
	if (myStatus.getHP() == 0)
		isDie = true;
	return true;
}
bool Character::checkDie() {
	return isDie;
}
int Character::beBuffedDefence(MyRGB input) {
	myStatus.addMyRGBDefence(input);
	return true;
}
int Character::beBuffedDamage(MyRGB input) {
	myStatus.addMyRGBDamage(input);
	return true;
}
Status* Character::getStatus() {
	return &myStatus;
}
int Character::setType(CharacterType type) {
	this->type = type;
	return 0;
}
CharacterType Character::getType() {
	return type;
}

int		Character::getIndex() {
	return _index;
}

void	Character::setIndex(int index) {
	if (index < 0 || index > 5) {
		printf("[OH] Index assign error!\n");
	}
	_index = index;
	return;
}
int		Character::getUsableSkill() {
	int num = rand() % mySkillSet.size();
	for (int i = num,cnt=0; cnt < mySkillSet.size(); i++,cnt++) {
		if (i == mySkillSet.size())
			i = 0;
		if (mySkillSet[i]->able())
			return i;
	}
	return 0;
}
void Character::printStatus() {
	std::string a;
	a += cocos2d::StringUtils::format("Type : [%d] |",this->getType());
	a += cocos2d::StringUtils::format("CurrentHP: [%d] |", this->getStatus()->getHP());
	a += cocos2d::StringUtils::format("Damage: [%d] |", this->getStatus()->getDamage());
	a += cocos2d::StringUtils::format("Defence: [%d]", this->getStatus()->getDefence());
	printf("%s\n", a.c_str());
}