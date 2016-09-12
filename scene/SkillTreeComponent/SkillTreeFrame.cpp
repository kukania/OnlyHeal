/*
FileName:	SkillTreeFrame.cpp
Revision:	2016/09/12 by PorcaM
*/

#include "SkillTreeFrame.h"
#include "skillinstance/Factory/HealSkillFactory.h"

SkillTreeFrame::SkillTreeFrame (SkillTree* pSkilltree){
	pSkilltree->initHealSkillTree ();
	for (TreeIt ti = pSkilltree->getBegin ();
		ti != pSkilltree->getEnd (); ti++){
		
	}
}

void SkillTreeFrame::initButton (){
	auto temp = new SkillButton ();
	sbv.push_back (temp);
	return;
}

SkillTreeFrame::~SkillTreeFrame (){
	for (vector<SkillButton*>::iterator vi = sbv.begin ();
		vi != sbv.end (); vi++){
		delete *vi;
	}
	sbv.clear();
}