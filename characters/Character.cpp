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
	if (myStatus.getHP() == 0)
		isDie = true;
	return true;
}
int Character::doAttack(float dt) {
	Character *input = this->list;
	//Skill 0 ´Â ÆòÅ¸, input 0 = monster 1=player
	Skill* temp;
	if (mySkillSet.size() - 1 == 0)
		temp = mySkillSet[0];
	else {
		temp = mySkillSet[rand() % (mySkillSet.size() - 1) + 1];
		temp = temp->able() ? temp : mySkillSet[0];
	}
	if (temp->isMulti()) {
		temp->activate(input, *this);
	}
	else {
		if (this->type == 1) {
			int agroT = -2;
			int obj = 0;
			for (int i = 2; i <= 4; i++) {
				if (agroT < input[i].getStatus()->getAgro()) {
					agroT = input[i].getStatus()->getAgro();
					obj = i;
				}
			}
			temp->activate(&input[obj], *this);
		}
		else if (this->type != 0) {
			temp->activate(&input[1], *this);
		}
	}
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
void Character::setCharacterList(Character *input) {
	this->list = input;
}

Character * Character::getCharacterList() {
	return list;
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