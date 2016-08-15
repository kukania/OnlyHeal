#pragma once
#include "parts/Status.h"
#include "parts/Skill.h"
#include "parts/Tier.h"
#include<vector>
class Character {
private:
	int type;
	bool isDie;
	Status myStatus;
public:
	std::vector<Skill*> mySkillSet;
	Character() {
		isDie = false;
		type = 0;
	}
	Character(Tier tier):myStatus(tier) {}
	int beAttacked(int);
	int beBuffedDefence(RGB);
	int beBuffedDamage(RGB);
	Status getStatus();
	int doAttack(Character *);
	bool checkDie();
};