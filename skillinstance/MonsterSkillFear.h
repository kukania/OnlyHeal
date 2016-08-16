#pragma once
#include"../parts/Skill.h"
#include"../parts/Tier.h"
class MonsterSkillFear:public Skill{
private:
	Tier myTier;
	float factor;
public:
	MonsterSkillFear();
	MonsterSkillFear(float, Tier,SkillID now, string, SkillID prev, time_ms, time_s);
	string getName();
	virtual int activate(Character *t, Character c);
};