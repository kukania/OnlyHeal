/*
FileName:	Monster.h
Revision:	? by Kukania
Modified:	2016/09/07 by PorcaM
*/

#pragma once
#include "Character.h"
class Monster :public Character {
private:
	int targetNum;
public:
	Monster(Tier tier);
	Monster();
	int doAttack(float);
	int setFindTarget(Character ** t);
	virtual void	initSkillSet(int);
};