/*
FileName:	SkillTreeFrame.cpp
Revision:	2016/09/12 by PorcaM
*/

#include "SkillTreeFrame.h"
#include "skillinstance/Factory/HealSkillFactory.h"

SkillTreeFrame::SkillTreeFrame (ST_TYPE type){
	if (type == HealSkilltree) {
		st.initHealSkillTree ();
		pSf = new HealSkillFactory ();
		pSf->initAllSkills();
	}
	else if (type == BuffSkilltree){
		// no buffskilltree now
	}
	else if (type == DebuffSkilltree){
		// no debuffskilltree now
	}
	for (TreeIt ti = st.getBegin ();
		ti != st.getEnd (); ti++){
		insertButton (pSf->getSkill (ti->first));
	}
}

void SkillTreeFrame::insertButton (Skill* skill){
	auto button = new SkillButton (skill);
	button->setPosition (Vec2 (0, 0));
	sbv.push_back (button);
	return;
}

SkillTreeFrame::~SkillTreeFrame (){
	for (vector<SkillButton*>::iterator vi = sbv.begin ();
		vi != sbv.end (); vi++){
		delete *vi;
	}
	delete pSf;
	sbv.clear();
}