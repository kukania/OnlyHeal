#pragma once
#include "Character.h"
#include "MeleeNPC.h"
#include "TankNPC.h"
#include "RangeNPC.h"
#include "Monster.h"
#include<string>
//user
#include <random>

Character* Character::create(const std::string& file, Tier t, string& typeOfChar, int skill) {
	Character *myCharacter=nullptr;
	if (typeOfChar.compare("User")==0) {
		//user
	}
	else if (typeOfChar.compare("MeleeNPC") == 0) {
		myCharacter = new MeleeNPC(t, skill);
	}
	else if (typeOfChar.compare("Monster") == 0) {
		myCharacter = new Monster(t);
	}
	else if (typeOfChar.compare("RangeNPC") == 0) {
		myCharacter = new RangeNPC(t, skill);
	}
	else if (typeOfChar.compare("TankNPC") == 0) {
		myCharacter = new TankNPC(t, skill);
	}
	if (myCharacter && myCharacter->initWithFile(file.c_str()))
	{
		myCharacter->autorelease();
		return myCharacter;
	}
	CC_SAFE_DELETE(myCharacter);
	return nullptr;
}
int Character::beAttacked(int damage) {
	myStatus.addHP(-damage);
	if (myStatus.getHP() == 0)
		isDie = true;
	return true;
}
int Character::doAttack(float dt) {
	Character *input = this->list;
	//Skill 0 ´Â ÆòÅ¸, input 0 = player 1=monster
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
int Character::setType(int type) {
	this->type = type;
	return 0;
}
int Character::getType() {
	return type;
}
void Character::setCharacterList(Character *input) {
	this->list = input;
}

Character * Character::getCharacterList() {
	return list;
}