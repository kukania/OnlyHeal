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
	damage = t[1].getStatus()->getDamage()/factor;
	for (int i = 0; i < 6; i++) {
		if (i == 1) continue;
		//내부 정의
	}
}

string MonsterSkillFear::getName() {
	string p = Skill::getName();
	//level 붙여주기
}