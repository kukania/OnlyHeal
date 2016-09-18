/*
FileName: 	TankSkillFactory.cpp
Revision:	2016/09/05 by PorcaM
*/

#include "TankSkillFactory.h"
#include "skillinstance\TankSkill.h"
#include <string>

Skill*	TankSkillFactory::createSkill() {
	Skill* skill = new TankSkill();
	return skill;
}

Skill*	TankSkillFactory::createSkill(SkillID ID, string name, time_ms cooltime, time_s time, bool multi, float factor) {
	Skill* skill = new TankSkill(ID, name, cooltime, time, multi, factor);
	return skill;
}

void	TankSkillFactory::initAllSkills() {
	clearFactory ();
	string  sLevelPrefix[7]		= { "기본", "숙련", "완숙", "전문", "기적", "전설", "신화" };
	float   fLevelFactor[7]		= { 1.0f, 1.2f, 1.5f, 2.0f, 3.0f, 5.0f, 10.0f };
	string	sTypePostfix[2]		= { "도발", "포효" };
	int		iTypeTime[2]		= { 1, 10 };
	int		iTypeFactor[2]		= { 1, 2 };
	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < 7; i++) {
			SkillID id			= i + (j * 7) + 1;
			string	skillName	= sLevelPrefix[i] + sTypePostfix[j];
			time_ms cooltime	= fLevelFactor[i] * 1000;
			time_s	time		= iTypeTime[j];
			bool	multi		= false;
			float	factor		= fLevelFactor[i] * iTypeFactor[j];
			pushSkill (createSkill(id, skillName, cooltime, time, multi, factor));
		}
	}
	return;
}