/* ============================================================
FileName: 	PlayerInfo.h
Revision: 	2016/09/27 by PorcaM
Modified: 	2016/10/01 by PorcaM
============================================================ */

#include "scene\SkillTreeComponent\PlayerInfo.h"

#include <string>

/* ============================================================
	Getter and Setter. 
============================================================ */
auto PlayerInfo::get_skill_num(){
	return skill_num_;
}

void PlayerInfo::set_skill_num(int skill_num){
	if (skill_num < 0){
		skill_num = 0;
	}
	skill_num_ = skill_num;
	return;
}

auto PlayerInfo::get_point(){
	return point_;
}

void PlayerInfo::set_point(Point point){
	if (point < 0){
		assert(false && "point cannot be unsigned.");
		point = 0;
	}
	point_ = point;
	UpdateLabelPoint();
	return;
}

PlayerInfo::SkillVec PlayerInfo::get_slot(){
	return slot_;
}

ui::ScrollView *PlayerInfo::get_scrollview(){
	return scrollview_;
}

/* ============================================================
	Public
============================================================ */
PlayerInfo::PlayerInfo(){
	get_slot().reserve(kMaxSkillNum);
	InitScrollview();
	InitLabelPoint();
	set_point(10);
	set_skill_num(0);
}
PlayerInfo::~PlayerInfo(){
	get_slot().clear();
}
void PlayerInfo::UpdateLabelPoint(){
	string text = "Your Point: " + to_string(get_point());
	label_point_->setString(text);
	return;
}

void PlayerInfo::InitScrollview(){
	int scrollview_height = 150;
	int scrollview_inner_width = 300;
	scrollview_ = ui::ScrollView::create();
	scrollview_->setContentSize(Size(280, scrollview_height));
	scrollview_->setInnerContainerSize(Size(
											scrollview_inner_width, 
											scrollview_height));
	scrollview_->setBackGroundImageScale9Enabled(true);
	scrollview_->setBackGroundImage("images/skilltree/rect.png");
	scrollview_->setDirection(ui::ScrollView::Direction::HORIZONTAL);
	scrollview_->setBounceEnabled(true);
	scrollview_->setTouchEnabled(true);
	scrollview_->setSwallowTouches(false);
	scrollview_->setName("scene_skilltreecomponent_playerinfo_scrollView");
	scrollview_->setAnchorPoint (Vec2 (0.5f, 0));
	scrollview_->setPosition (Vec2 (0, -300));
	return;
}

void PlayerInfo::InitLabelPoint(){
	string text = "Your Point: " + to_string(get_point());
	string font = "fonts/sdCrayon.ttf";
	int size = 24;
	label_point_ = Label::create(text, font, size);
	label_point_->setAnchorPoint(Vec2(0, 0.5f));
	label_point_->setPosition(Vec2(0, 120));
	label_point_->setTextColor(Color4B(0, 0, 0, 255));
	get_scrollview()->addChild(label_point_);
	return;
}