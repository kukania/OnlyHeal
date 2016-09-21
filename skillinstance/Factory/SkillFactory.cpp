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
SkillFactory::~SkillFactory(){\
	clearFactory();
}

SVI 	SkillFactory::getBegin (){
	return Akashic.begin ();
}

SVI 	SkillFactory::getEnd (){
	return Akashic.end ();
}

void 	SkillFactory::clearFactory (){
	for (SVI vi = getBegin (); vi != getEnd (); vi++){
		delete *vi;
	}
	Akashic.clear ();
	return;
}

void 	SkillFactory::pushSkill (Skill* pSkill){
	Akashic.push_back (pSkill);
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
	if (num < 1){
		num = 1;
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