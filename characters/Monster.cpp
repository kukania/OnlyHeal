/*
FileName:	Monster.cpp
Revision:	? by Kukania
Modified:	2016/09/07 by PorcaM
*/

#pragma once
#include "Monster.h"
#include"../skillinstance/RangeSkill.h"
#include"../skillinstance/MonsterSkillFear.h"
int Monster::setFindTarget(Character **t) {
	int target=2;
	int max = 0;
	for (int i = 0; i < 6; i++) {
		int temp;
		if (i == 1)continue;
		if ((temp = t[i]->getStatus()->getAgro()) > max) {
			target = i;
			max = temp;
		}
	}
	this->setType(monster);
	this->targetNum = target;
	return target;
}
Monster::Monster(Tier myTier)
	:Character(myTier) {
	Skill * firstSkill = new RangeSkill(1, "전체강타", 0, 0, true, 1);
	Character::mySkillSet.push_back(firstSkill);
	firstSkill = new MonsterSkillFear(0.1, myTier, 100, "fre", 10, 10);
	Character::mySkillSet.push_back(firstSkill);
}

Monster::Monster() :Character() {

}

int Monster::doAttack(float d) {
	this->setFindTarget(this->getCharacterList());
	Character::doAttack(d);
	return 0;
}

void Monster::initSkillSet(int skillnum) {
	return;
}