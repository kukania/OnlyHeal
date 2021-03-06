/*
FileName:	Character.h
Revision:	? by Kukania
Modified:	2016/09/07 by PorcaM
*/

#pragma once
#include "parts/Status.h" 	//Problem
#include "parts/Skill.h"
#include "parts/Tier.h"
#include "cocos2d.h"
#include<queue>
#include <vector>

enum CharacterType {
	monster,healer, melee, range, tanker, unknown
};

class Character :public cocos2d::Sprite{
private:
	CharacterType	type;
	bool			isDie;
	Status			myStatus;
	int				_index;		/* In raid, each character need their own index */
public:
	std::queue<int>		attackedDamage; /*damaged check*/
	double			_timer;		/*activate timer*/
	static Character* create(Tier t, const char* typeOfChar, int index);
	std::vector<Skill*> mySkillSet;
	Character() {
		isDie = false;
		type = healer;
	}
	Character(Tier tier) :myStatus(tier) {
		isDie = false;
	}
	int beAttacked(int);
	int beBuffedDefence(MyRGB);
	int beBuffedDamage(MyRGB);
	int setType(CharacterType);
	CharacterType getType();
	Status* getStatus();

	//int doAttack(float);
	bool			checkDie();
	int				getIndex();
	void			setIndex(int);
	virtual void	initSkillSet(int) = 0;
	int				getUsableSkill();
	/*for debug*/
	void printStatus();
	~Character() {
		CCLOG("Character destructor");
	}
};