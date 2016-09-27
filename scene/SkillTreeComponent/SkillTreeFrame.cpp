/* ============================================================
FileName:	SkillTreeFrame.cpp
Revision:	2016/09/12 by PorcaM
Modified: 	2016/09/27 by PorcaM
============================================================ */

#include "SkillTreeFrame.h"

#include "skillinstance/Factory/HealSkillFactory.h"
#include "skillinstance/Factory/BuffSkillFactory.h"
#include "skillinstance/Factory/DebuffSkillFactory.h"

// SkillTreeFrame::
// SkillTreeFrame (ST_TYPE type){
// 	/* Allocate members */
// 	_factories = new SkillFactory*[3];
// 	_factories[0] = new HealSkillFactory ();
// 	_factories[1] = new BuffSkillFactory ();
// 	_factories[2] = new DebuffSkillFactory ();
// 	for (int i = 0; i < 3; i++)
// 		_factories[i] -> initAllSkills ();
// 	/* Set values */
// 	initWithType (type);
// }

// void 
// SkillTreeFrame::
// initWithType (ST_TYPE type){
// 	ClearContents();
// 	SkillFactory* factory = _factories[(int)type];
// 	/*if		(type == HealSkilltree)
// 		_skilltree.initHealSkillTree ();
// 	else if (type == BuffSkilltree)
// 		_skilltree.initBuffSkillTree ();*/
// 	int i = 0;
// 	for (TreeIt ti = get_skilltree().getBegin(); ti != get_skilltree().getEnd (); ti++){
// 		Skill* 	pSkill 		= factory -> getSkill (ti->first);
// 		Vec2 	position 	= Vec2 (100*++i, 100);
// 		//insertButton (pSkill, ti->second, position);
// 	}
// 	return;
// }

/* ============================================================
	Renewaled functions on 27th. 
============================================================ */
SkillTreeFrame::SkillTreeFrame(){
	scrollview_height_ 			= 400;
	scrollview_inner_width_ 	= 1200;
	InitScrollView();
	InitWithType(Skill::kHeal);
}

void SkillTreeFrame::InitWithType(Skill::Type type) {
		ClearContents();
		int i = 0;
		SkillFactory *factory = get_factory();
		for (auto it = get_skilltree()->getBegin();
			it != get_skilltree()->getEnd(); it++) {
			Skill *skill = factory->getSkill(it->first);
			InsertButton(skill);
		}
		return;
	}

void SkillTreeFrame::ClearContents() {
	ClearScrollview ();		/* This order is VERY important! */
	ClearButtons (); 		/* Never call this function before above! */
	return;
}

void SkillTreeFrame::InsertButton(Skill *skill){
	SkillNode *node = it->second;
	SkillNode *prev = get_skilltree()->findSkill(node->getPrev());
	auto button = new SkillButton(skill, node, prev);
	get_scrollview()->addChild(button);
	return;
}

ui::ScrollView *SkillTreeFrame::get_scrollview(){
	return scrollview_;
}

Skill::Type SkillTreeFrame::get_type(){
	return type_;
}

void SkillTreeFrame::set_type(Skill::Type type){
	if (static_cast<int>(type) < 3) {
		type_ = type;
	} else {
		assert(false);
	}
	return;
}

void SkillTreeFrame::InitScrollView(){
	scrollview_ = ui::ScrollView::create();
	scrollview_->setContentSize(Size(280, scrollview_height_));
	scrollview_->setInnerContainerSize(Size(
											scrollview_inner_width_, 
											scrollview_height_));
	scrollview_->setBackGroundImageScale9Enabled(true);
	scrollview_->setBackGroundImage("images/skilltree/rect.png");
	scrollview_->setDirection(ui::ScrollView::Direction::HORIZONTAL);
	scrollview_->setBounceEnabled(true);
	scrollview_->setTouchEnabled(true);
	scrollview_->setSwallowTouches(false);
	scrollview_->setName("scrollView");
	scrollview_->setAnchorPoint (Vec2 (0.5f, 0.98f));
	scrollview_->setPosition (Vec2 (0, 185));
	return;
}

void SkillTreeFrame::ClearScrollview (){
	scrollview_ -> removeAllChildren ();
	return;
}

void SkillTreeFrame::ClearButtons (){
	for (auto vi = button_vec_.begin (); vi != button_vec_.end (); vi++){
		delete *vi;
	}
	button_vec_.clear ();
	return;
}

SkillFactory *SkillTreeFrame::get_factory(){
	return skill_info_.get_factory_by_type(type_);
}

SkillTree *SkillTreeFrame::get_skilltree(){
	return skill_info_.get_skilltree_by_type(type_);
}