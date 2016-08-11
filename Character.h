#pragma once
#include "parts/Status.h"
#include "parts/Skill.h"
#include "parts/Tier.h"
#include<list>
class Character {
private:
	int type;
	bool isDie;
	Status myStatus;
	list<Skill*> mySkillSet;
public:
	Character() {
		isDie = false;
		type = 0;
	}
	Character(Tier tier):myStatus(tier) {}
	int beAttacked(int);
	int beBuffedDefence(RGB);
	int beBuffedDamage(RGB);
	int doAttack();
	bool checkDie();
};