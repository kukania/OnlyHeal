#pragma once
#include"../parts/Skill.h"
#include"../parts/Tier.h"
class MonsterSkillFear:public Skill{
private:
	Tier myTier;
	float factor;
public:
	MonsterSkillFear();
	MonsterSkillFear(float, Tier,SkillID now, string, time_ms, time_s);
	string getName();
	int setTier(Tier);
	virtual int activate(Character **t, Character &c, int);
	virtual int activate(Character **t, Character &c);
};