/*
FileName:	Monster.cpp
Revision:	? by Kukania
Modified:	2016/09/07 by PorcaM
*/

#pragma once
#include "Monster.h"
#include"skillinstance/RangeSkill.h"
#include"skillinstance/MonsterSkillFear.h"
#include"skillinstance/MonsterSkillAttack.h"
int Monster::setFindTarget(Character **t) {
	int target=2;
	int max = 0;
	for (int i = 2; i < 6; i++) {
		int temp;
		if (!t[i]->checkDie()&&((temp = t[i]->getStatus()->getAgro()) > max)) {
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
	Skill * firstSkill = new MonsterSkillAttack(1, myTier,1000,"attack", 0, 0);
	Character::mySkillSet.push_back(firstSkill);
	firstSkill = new MonsterSkillFear(0.1, myTier, 100, "fre", 10, 10);
	Character::mySkillSet.push_back(firstSkill);
	this->getStatus()->setMaxHPDefault(this->getStatus()->getMaxHP() * 9);
}

Monster::Monster() :Character() {

}
void Monster::initSkillSet(int skillnum) {
	return;
}