#pragma once
#include "../parts/Status.h" 	//Problem
#include "../parts/Skill.h"
#include "../parts/Tier.h"
#include "cocos2d.h"
#include<vector>

class Character{
private:
	int type;
	bool isDie;
	Status myStatus;
	Character *list;
public:
	std::vector<Skill*> mySkillSet;
	Character() {
		isDie = false;
		type = 0;
	}
	Character(Tier tier) :myStatus(tier) {}
	int beAttacked(int);
	int beBuffedDefence(MyRGB);
	int beBuffedDamage(MyRGB);
	int setType(int);
	int getType();
	Status* getStatus();
	void setCharacterList(Character *);
	Character * getCharacterList();
	int doAttack(float);
	bool checkDie();
};