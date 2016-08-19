#pragma once
#include"MonsterSkillFear.h"
#include"../characters/Character.h"
MonsterSkillFear::MonsterSkillFear():Skill(1000, "fear", 0, 0, 0, 0, false) {
	factor = 0;
}
MonsterSkillFear::MonsterSkillFear(float myFloat, Tier T_input, SkillID now, string S_name, SkillID prev, time_ms cool, time_s c):Skill(now,S_name,prev,cool,c,10,true){
	myTier = T_input;
	this->myTier = myFloat;
}
int MonsterSkillFear::setTier(Tier in) {
	myTier = in;
	return 0;
}
int MonsterSkillFear::activate(Character *t, Character &c) {
	int damage[6], defence[6];
	MyRGB rgbDamage[6], rgbDefence[6];
	for (int i = 0; i < 6; i++) {
		if (i == 1) continue;
		damage[i] = factor*t[i].getStatus()->getDamage();
		t[i].getStatus()->addDamage(-1 * damage[i]);
	
		defence[i] =factor* t[i].getStatus()->getDefence();
		t[i].getStatus()->addDefence(-1 * defence[i]);
		
		rgbDamage[i] = (t[i].getStatus()->getMyRGBDamage())*factor;
		t[i].getStatus()->addMyRGBDamage(rgbDamage[i]*-1);
		
		rgbDefence[i] = t[i].getStatus()->getMyRGBDefence()*factor;
		t[i].getStatus()->addMyRGBDefence(rgbDefence[i]*-1);
	}
	
	
	//sleep

	for (int i = 0; i < 6; i++) {
		if (i == 1) continue;
		t[i].getStatus()->addDamage( damage[i]);
		t[i].getStatus()->addDefence(defence[i]);
		t[i].getStatus()->addMyRGBDamage(rgbDamage[i]);
		t[i].getStatus()->addMyRGBDefence(rgbDefence[i]);
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