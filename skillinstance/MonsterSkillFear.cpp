#pragma once
#include"MonsterSkillFear.h"
#include"../Character.h"
MonsterSkillFear::MonsterSkillFear():Skill(1000, "fear", 0, 0, 0, 0, false) {
	factor = 0;
}
MonsterSkillFear::MonsterSkillFear(float myFloat, Tier T_input, SkillID now, string S_name, SkillID prev, time_ms cool, time_s c):Skill(now,S_name,prev,cool,c,10,true){
	myTier = T_input;
	this->myTier = myFloat;
}
int MonsterSkillFear::activate(Character *t, Character c) {
	int damage, defence;
	RGB rgbDamage, rgbDefence;
	for (int i = 0; i < 6; i++) {
		if (i == 1) continue;
		damage=t[i].getStatus()->getDamage()*factor;
		defence = t[i].getStatus()->getDefence()*factor;
	}
}