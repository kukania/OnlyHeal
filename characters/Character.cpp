#pragma once
#include "Character.h"
#include <random>
int Character::beAttacked(int damage) {
	myStatus.addHP(-damage);
	if (myStatus.getHP() == 0)
		isDie = true;
	return true;
}
int Character::doAttack(Character *input) {
	//Skill 0 ´Â ÆòÅ¸, input 0 = player 1=monster
	Skill* temp = mySkillSet[rand() % mySkillSet.size() + 1];
	temp = temp->able() ? temp : mySkillSet[0];
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