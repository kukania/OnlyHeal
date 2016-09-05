/*
FileName: 	SkillFactory.cpp
Revision: 	2016/08/23 by PorcaM
Modified:	2016/09/05 by PorcaM
*/

#include "SkillFactory.h"

SkillFactory::SkillFactory() {
	Akashic.clear();
}

Skill*	SkillFactory::createSkill(SkillType type) {
	Skill* skill = NULL;
	return skill;
}

Skill**	SkillFactory::getSkillsList(int num) {
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