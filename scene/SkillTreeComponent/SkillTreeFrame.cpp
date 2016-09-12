/*
FileName:	SkillTreeFrame.cpp
Revision:	2016/09/12 by PorcaM
*/

#include "SkillTreeFrame.h"
#include "skillinstance/Factory/HealSkillFactory.h"

SkillTreeFrame::SkillTreeFrame (ST_TYPE type){
	initScrollView ();
	if (type == HealSkilltree) {
		_st.initHealSkillTree ();
		_pSf = new HealSkillFactory ();
		_pSf->initAllSkills();
	}
	else if (type == BuffSkilltree){
		// no buffskilltree now
	}
	else if (type == DebuffSkilltree){
		// no debuffskilltree now
	}
	for (TreeIt ti = _st.getBegin ();
		ti != _st.getEnd (); ti++){
		insertButton (_pSf->getSkill (ti->first));
	}
}

void SkillTreeFrame::initScrollView(){
	_scrollView = ui::ScrollView::create();
	_scrollView->setContentSize(Size(500, 110));
	_scrollView->setInnerContainerSize(Size(1080, 110));
	_scrollView->setBackGroundImageScale9Enabled(true);
	_scrollView->setBackGroundImage("images/raid/bg.png");
	_scrollView->setDirection(ui::ScrollView::Direction::HORIZONTAL);
	_scrollView->setBounceEnabled(true);
	_scrollView->setTouchEnabled(true);
	_scrollView->setSwallowTouches(false);
	_scrollView->setVisible(true);
	_scrollView->setName("scrollView");
	return;
}

void SkillTreeFrame::insertButton (Skill* skill){
	auto button = new SkillButton (skill);
	button->setPosition (Vec2 (0, 0));
	_sbv.push_back (button);
	_scrollView->addChild (button);
	return;
}

ui::ScrollView* SkillTreeFrame::getScrollView (){
	return _scrollView;
}

SkillTreeFrame::~SkillTreeFrame (){
	for (vector<SkillButton*>::iterator vi = _sbv.begin ();
		vi != _sbv.end (); vi++){
		delete *vi;
	}
	delete _pSf;
	_sbv.clear();
}