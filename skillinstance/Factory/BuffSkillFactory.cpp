/*
FileName: 	BuffSkillFactory.cpp
Revision:	2016/09/17 by PorcaM
*/

#include "BuffSkillFactory.h"
#include "skillinstance\BuffSkill.h"
#include <string>

Skill*	BuffSkillFactory::createSkill() {
	Skill* skill = new HealSkill();
	return skill;
}

Skill*	BuffSkillFactory::createSkill(SkillID ID, string name, time_ms cooltime, time_s time, bool multi, float factor) {
	Skill* skill = new HealSkill(ID, name, cooltime, time, multi, factor);
	return skill;
}

void	BuffSkillFactory::initAllSkills() {
	clearFactory ();
	string  sLevelPrefix[7]		= { "±âº»", "¼÷·Ã", "¿Ï¼÷", "Àü¹®", "±âÀû", "Àü¼³", "½ÅÈ­" };
	float   fLevelFactor[7]		= { 1.0f, 1.2f, 1.5f, 2.0f, 3.0f, 5.0f, 10.0f };
	string	sTypePostfix[3]		= { "Èú¸µ", "±¤Èú", "¹°¾à" };
	int		iTypeTime[3]		= { 1, 1, 10 };
	int		iTypeCooltime[3]	= { 1, 2, 1 };
	int		iTypeFactor[3]		= { 1, 1, 2 };
	bool	bTypeMulti[3]		= { false, true, false };
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 7; i++) {
			SkillID id			= i + (j * 7) + 1;
			string	skillName	= sLevelPrefix[i] + sTypePostfix[j];
			time_ms cooltime	= fLevelFactor[i] * iTypeCooltime[j] * 1000;
			time_s	time		= iTypeTime[j];
			bool	multi		= bTypeMulti[j];
			float	factor		= fLevelFactor[i] * iTypeFactor[j];
			pushSkill (createSkill(id, skillName, cooltime, time, multi, factor));
		}
	}
	return;
}