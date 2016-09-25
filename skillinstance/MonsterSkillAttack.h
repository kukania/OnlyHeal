#pragma once
#include"../parts/Skill.h"
#include"../parts/Tier.h"
class MonsterSkillAttack : public Skill {
private:
public:
	MonsterSkillAttack();
	MonsterSkillAttack(float, Tier, SkillID now, string, time_ms, time_s);
	virtual int activate(Character **t, Character &c, int);
	virtual int activate(Character **t, Character &c);
};