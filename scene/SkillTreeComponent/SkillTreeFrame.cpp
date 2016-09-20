/*
FileName:	SkillTreeFrame.cpp
Revision:	2016/09/12 by PorcaM
Modified: 	2016/09/19 by PorcaM
*/

#include "SkillTreeFrame.h"
#include "skillinstance/Factory/HealSkillFactory.h"
#include "skillinstance/Factory/BuffSkillFactory.h"
#include "skillinstance/Factory/DebuffSkillFactory.h"

SkillTreeFrame::SkillTreeFrame (ST_TYPE type){
	/* Allocate members */
	_factories = new SkillFactory*[3];
	_factories[0] = new HealSkillFactory ();
	_factories[1] = new BuffSkillFactory ();
	_factories[2] = new DebuffSkillFactory ();
	for (int i = 0; i < 3; i++)
		_factories[i] -> initAllSkills ();
	/* Set values */
	_height 	= 400;
	_innerWidth = 1200;
	initScrollView();
	initWithType (type);
}

void SkillTreeFrame::initWithType (ST_TYPE type){
	clearScrollview ();		/* This order is VERY important! */
	clearButtons (); 		/* Never call this function before above! */
	SkillFactory* factory = _factories[(int)type];
	if		(type == HealSkilltree)
		_skilltree.initHealSkillTree ();
	else if (type == BuffSkilltree)
		_skilltree.initBuffSkillTree ();
	int i = 0;
	for (TreeIt ti = _skilltree.getBegin (); ti != _skilltree.getEnd (); ti++){
		Skill* 	pSkill 		= factory -> getSkill (ti->first);
		Vec2 	position 	= Vec2 (100*++i, 100);
		insertButton (pSkill, ti->second, position);
	}
	return;
}

void SkillTreeFrame::initScrollView(){
	_scrollview = ui::ScrollView::create();
	_scrollview->setContentSize (Size (280, _height));
	_scrollview->setInnerContainerSize(Size (_innerWidth, _height));
	_scrollview->setBackGroundImageScale9Enabled(true);
	_scrollview->setBackGroundImage("images/skilltree/rect.png");
	_scrollview->setDirection(ui::ScrollView::Direction::HORIZONTAL);
	_scrollview->setBounceEnabled(true);
	_scrollview->setTouchEnabled(true);
	_scrollview->setSwallowTouches(false);
	_scrollview->setName("scrollView");
	_scrollview->setAnchorPoint (Vec2 (0.5f, 0.98f));
	_scrollview->setPosition (Vec2 (0, 185));
	return;
}

void SkillTreeFrame::clearScrollview (){
	_scrollview -> removeAllChildren ();
	return;
}

void SkillTreeFrame::clearButtons (){
	for (vector<SkillButton*>::iterator vi = _buttons.begin ();
		vi != _buttons.end (); vi++){
		delete *vi;
	}
	_buttons.clear ();
	return;
}

void SkillTreeFrame::insertButton (Skill* skill, SkillNode* node, Vec2 position){
	auto button = new SkillButton (skill, node, _skilltree.findSkill (node->getPrev ()));
	button->setPosition (position);
	_buttons.push_back (button);
	_scrollview->addChild (button);
	return;
}

ui::ScrollView* SkillTreeFrame::getScrollView (){
	return _scrollview;
}

SkillTreeFrame::~SkillTreeFrame (){
	clearButtons ();
	for (int i = 0; i < 3; i++){
		delete _factories[i];
	}
	delete[] _factories;
	_buttons.clear();
}