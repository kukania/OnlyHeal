/*
FileName:	Character.h
Revision:	? by Kukania
Modified:	2016/08/25 by PorcaM
*/

#pragma once
#include "../parts/Status.h" 	//Problem
#include "../parts/Skill.h"
#include "../parts/Tier.h"
#include "cocos2d.h"
#include <vector>

enum CharacterType {
	healer, melee, range, tanker, monster, unknown
};

class Character :public cocos2d::Sprite{
private:
	CharacterType	type;
	bool			isDie;
	Status			myStatus;
	Character		*list;
public:
	static Character* create(Tier t, string& typeOfChar, int skill);
	std::vector<Skill*> mySkillSet;
	Character() {
		isDie = false;
		type = unknown;
	}
	Character(Tier tier) :myStatus(tier) {}
	int beAttacked(int);
	int beBuffedDefence(MyRGB);
	int beBuffedDamage(MyRGB);
	int setType(CharacterType);
	CharacterType getType();
	Status* getStatus();
	void setCharacterList(Character *);
	Character * getCharacterList();
	int doAttack(float);
	bool checkDie();
};