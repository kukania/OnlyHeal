#include"MonsterSkillAttack.hpp"
#include"characters/Monster.h"
#include"myUtility.h"
MonsterSkillAttack::MonsterSkillAttack():Skill(4000, "basic attack", 0, 0, debuff, false) {
	
}
MonsterSkillAttack::MonsterSkillAttack(float myFloat, Tier T_input, SkillID now, string S_name, time_ms cool, time_s c) 
	:Skill(now, S_name, cool, c, unknown_skill, false) {
}

int MonsterSkillAttack::activate(Character **t, Character &c, int) {
	return 0;
}
int MonsterSkillAttack::activate(Character **t, Character &c) {
	Monster* m = (Monster*)&c;
	this->setCooldown();
	int idx=m->setFindTarget(t);
	int power = 1;
	float _factor = 1.0f;
	int amount = DAMAGE_FOMULA(c, t[idx]);
	t[idx]->beAttacked(amount);
	return idx;
}