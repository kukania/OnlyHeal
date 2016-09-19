/*
FileName:	Character.h
Revision:	? by Kukania
Modified:	2016/09/07 by PorcaM
*/

#pragma once
#include "../parts/Status.h" 	//Problem
#include "../parts/Skill.h"
#include "../parts/Tier.h"
#include "cocos2d.h"
#include <vector>

enum CharacterType {
	monster,healer, melee, range, tanker, unknown
};

class Character :public cocos2d::Sprite{
private:
	CharacterType	type;
	bool			isDie;
	Status			myStatus;
	Character**		list; 		/* I cannot understand why character need this list */
	int				_index;		/* In raid, each character need their own index */
public:
	static Character* create(Tier t, const char* typeOfChar, int index);
	std::vector<Skill*> mySkillSet;
	Character() {
		isDie = false;
		type = healer;
	}
	Character(Tier tier) :myStatus(tier) {}
	int beAttacked(int);
	int beBuffedDefence(MyRGB);
	int beBuffedDamage(MyRGB);
	int setType(CharacterType);
	CharacterType getType();
	Status* getStatus();
	void setCharacterList(Character **);
	Character** getCharacterList();
	//int doAttack(float);
	bool checkDie();
	int				getIndex();
	void			setIndex(int);
	virtual void	initSkillSet(int) = 0;
	int				getUsableSkill();
};