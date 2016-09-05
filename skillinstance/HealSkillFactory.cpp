/*
FileName: 	HealSkillFactory.cpp
Revision:	2016/09/05 by PorcaM
*/

#include "HealSkillFactory.h"
#include "HealSkill.h"
#include <string>
#include <stdlib.h>
#include <set>

HealSkillFactory::HealSkillFactory() { }

Skill*	HealSkillFactory::createSkill() {
	Skill* skill = new HealSkill();
	return skill;
}

Skill*	HealSkillFactory::createSkill(SkillID ID, string name, time_ms cooltime, time_s time, bool multi, float factor) {
	Skill* skill = new HealSkill(ID, name, cooltime, time, multi, factor);
	return skill;
}

Skill*	HealSkillFactory::getSkill(int index) {
	return Akashic[index];
}

void	HealSkillFactory::initAllSkills() {
	Akashic.clear();
	string  sLevelPrefix[7]		= { "±âº»", "¼÷·Ã", "¿Ï¼÷", "Àü¹®", "±âÀû", "Àü¼³", "½ÅÈ­" };
	float   fLevelFactor[7]		= { 1.0f, 1.2f, 1.5f, 2.0f, 3.0f, 5.0f, 10.0f };
	string	sTypePostfix[3]		= { "Èú¸µ", "±¤Èú", "Èú»ù" };
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
			Akashic.push_back(createSkill(id, skillName, cooltime, time, multi, factor));
		}
	}
	return;
}

Skill**	HealSkillFactory::getSkillsList(int num) {
	Skill**	skillList = new Skill*[num];
	set<int> indexList;
	while (indexList.size() < num) {
		int index = rand() % Akashic.size();
		indexList.insert(index);
	}
	int i = 0;
	for (set<int>::iterator si = indexList.begin();
		si != indexList.end(); si++) {
		skillList[i++] = Akashic[*si];
	}
	return skillList;
}