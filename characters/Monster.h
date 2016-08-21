#pragma once
#include "Character.h"
class Monster :public Character {
private:
	int targetNum;
public:
	Monster(Tier tier);
	Monster();
	int doAttack(float);
	int setFindTarget(Character * t);
};