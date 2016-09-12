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
	int i = 0;
	for (TreeIt ti = _st.getBegin ();
		ti != _st.getEnd (); ti++){
		Skill* 	pSkill 		= _pSf->getSkill (ti->first);
		Vec2 	position 	= Vec2 (100*++i, 100);
		insertButton (pSkill, position);
	}
}

void SkillTreeFrame::initScrollView(){
	_scrollView = ui::ScrollView::create();
	_scrollView->setContentSize(Size(280, 400));
	_scrollView->setInnerContainerSize(Size(1200, 400));
	_scrollView->setBackGroundImageScale9Enabled(true);
	_scrollView->setBackGroundImage("images/skilltree/rect.png");
	_scrollView->setDirection(ui::ScrollView::Direction::HORIZONTAL);
	_scrollView->setBounceEnabled(true);
	_scrollView->setTouchEnabled(true);
	_scrollView->setSwallowTouches(false);
	_scrollView->setName("scrollView");
	_scrollView->setAnchorPoint (Vec2 (0.5f, 0.98f));
	_scrollView->setPosition (Vec2 (0, 205));
	return;
}

void SkillTreeFrame::insertButton (Skill* skill, Vec2 position){
	auto button = new SkillButton (skill);
	button->setPosition (position);
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