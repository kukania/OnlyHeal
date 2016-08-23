#pragma once
#include "../parts/Status.h" 	//Problem
#include "../parts/Skill.h"
#include "../parts/Tier.h"
#include "cocos2d.h"
#include<vector>

class Character :public cocos2d::Sprite{
private:
	int type;
	bool isDie;
	Status myStatus;
	Character *list;
public:
	static Character* create(const string& file, Tier t, string& typeOfChar, int skill);
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