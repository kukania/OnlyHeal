#pragma once
#include"MonsterSkillFear.h"
#include"../characters/Character.h"
MonsterSkillFear::MonsterSkillFear()
	:Skill(1000, "fear", 0, 0, debuff, false) {
	factor = 0;
}
MonsterSkillFear::MonsterSkillFear(float myFloat, Tier T_input, SkillID now, string S_name, time_ms cool, time_s c)
	: Skill(now, S_name, cool, c, debuff, true) {
	myTier = T_input;
	this->myTier = myFloat;
	factor = (float)this->myTier.getValue()/10000;
}
int MonsterSkillFear::setTier(Tier in) {
	myTier = in;
	return 0;
}
int MonsterSkillFear::activate(Character **t, Character &c, int v) {
	setCooldown();
	for (int i = 2; i < 6; i++) {
		t[i]->getStatus()->addDamage(v * factor*t[i]->getStatus()->getDamage());
		t[i]->getStatus()->addDefence(v * factor* t[i]->getStatus()->getDefence());
		t[i]->getStatus()->addMyRGBDamage((t[i]->getStatus()->getMyRGBDamage())*factor*v);
		t[i]->getStatus()->addMyRGBDefence(t[i]->getStatus()->getMyRGBDefence()*factor*v);
	}

	return 0;
}

string MonsterSkillFear::getName() {
	string p = Skill::getName();
	string v = "";
	int le=myTier.getLevel();
	if (le / 10 != 0)v.push_back(le / 10 + '0');
	v.push_back(le % 10 + '0');
	return p + v;
}
int MonsterSkillFear::activate(Character **t, Character &c) {
	return 0;
}