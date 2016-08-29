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

Character* Character::create(Tier t, string& typeOfChar, int skill) {
	Character *myCharacter = nullptr;
	if (typeOfChar.compare("User")==0) {
		//user
	}
	else if (typeOfChar.compare("MeleeNPC") == 0) {
		myCharacter = new MeleeNPC(t, skill);
		myCharacter->setType(melee);
	}
	else if (typeOfChar.compare("Monster") == 0) {
		myCharacter = new Monster(t);
		myCharacter->setType(monster);
	}
	else if (typeOfChar.compare("RangeNPC") == 0) {
		myCharacter = new RangeNPC(t, skill);
		myCharacter->setType(range);
	}
	else if (typeOfChar.compare("TankNPC") == 0) {
		myCharacter = new TankNPC(t, skill);
		myCharacter->setType(tanker);
	}
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
	//Skill 0 �� ��Ÿ, input 0 = player 1=monster
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