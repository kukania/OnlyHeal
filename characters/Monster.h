/*
FileName:	Monster.h
Revision:	? by Kukania
Modified:	2016/09/07 by PorcaM
*/

#pragma once
#include "Character.h"
#include<queue>
class Monster :public Character {
private:
	int targetNum;
public:
	std::queue<int>		attackedDamage; /*damaged check*/
	Monster(Tier tier);
	Monster();
	int beAttacked(int);
	int setFindTarget(Character ** t);
	virtual void	initSkillSet(int);
};