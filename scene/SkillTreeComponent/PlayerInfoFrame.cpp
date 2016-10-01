/* ============================================================
FileName: 	PlayerInfoFrame.h
Revision: 	2016/10/01 by PorcaM
Modified: 	2016/10/01 by PorcaM
============================================================ */

#include "scene/SkillTreeComponent/PlayerInfoFrame.h"

#include <string>

/* ============================================================
	Getter and Setter. 
============================================================ */
auto PlayerInfoFrame::get_label_point(){
	return label_point_;
}
auto PlayerInfoFrame::get_scrollview(){
	return scrollview_;
}
auto PlayerInfoFrame::get_slot(){
	return slot_;
}
/* ============================================================
	Public
============================================================ */
PlayerInfoFrame::PlayerInfoFrame(){
	InitLabelPoint();
 	InitScrollview();
 	InitSlot();
}
void PlayerInfoFrame::InsertSkill(Skill *skill){

}
/* ============================================================
	Private
============================================================ */	
void PlayerInfoFrame::InitLabelPoint(){
	string text = "Player SKill Point: " + to_string(0);
	string font = "fonts/sdCrayon.ttf";
	int size = 24;
	label_point_ = Label::create(text, font, size);
	this->add(label_point_);
	return;
}
void PlayerInfoFrame::InitScrollview(){
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
	scrollview_->setName("playerinfoframe_scrollview");
	scrollview_->setAnchorPoint (Vec2 (0.5f, 0));
	scrollview_->setPosition (Vec2 (0, 0));
	this->add(scroll_view_);
	return;
}
void PlayerInfoFrame::InitSlot(){
	slot_.clear();
	return;
}