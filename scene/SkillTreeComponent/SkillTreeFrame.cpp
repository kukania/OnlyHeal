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
	
}