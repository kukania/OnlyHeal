/*
FileName: 	SkillFactory.cpp
Revision: 	2016/08/23 by PorcaM
Modified:	2016/09/05 by PorcaM
*/

#include "SkillFactory.h"
#include <stdlib.h>
#include <set>

SkillFactory::SkillFactory() {
	Akashic.clear();
}
SkillFactory::~SkillFactory(){
	for (SVI vi = Akashic.begin();
	vi != Akashic.end(); vi++){
		delete *vi; 	/* [PM_Caution] I cannot assure that this code is clear operation */
	}
}

SVI 	SkillFactory::getBegin (){
	return Akashic.begin ();
}

SVI 	SkillFactory::getEnd (){
	return Akashic.end ();
}

Skill*	SkillFactory::getSkill(int index) {
	return Akashic[index];
}

Skill*	SkillFactory::createSkill() {
	Skill* skill = NULL;
	return skill;
}

Skill**	SkillFactory::getSkillsList(int num) {
	if (num < Akashic.size ()){ 	/* num must be smaller than entire skill number */
		num = Akashic.size ();
	}
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