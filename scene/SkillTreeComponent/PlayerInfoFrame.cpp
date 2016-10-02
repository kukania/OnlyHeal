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
auto PlayerInfoFrame::get_icons(){
	return icons_;
}
/* ============================================================
	Public
============================================================ */
PlayerInfoFrame::PlayerInfoFrame(){
	InitLabelPoint(0);
 	InitScrollview();
 	InitIcons();
 	for (int i = 0; i < 10; ++i) {
 		InsertIcon(i, NULL);
 	}
}
PlayerInfoFrame::PlayerInfoFrame(PlayerInfo *player_info){
	InitLabelPoint(player_info->get_point());
	InitScrollview();
	InitIcons();
	auto slot = player_info->get_slot();
	int i;
	for (i = 0; i < slot->Size(); ++i) {
		InsertIcon(i, *(slot->FindSkillWithIndex(i)));
	}
	for (; i < 10; ++i) {
		InsertIcon(i, NULL);
	}
}
PlayerInfoFrame::~PlayerInfoFrame(){
	delete label_point_;
	delete scrollview_;
	for (auto it = icons_.begin(); it != icons_.end(); it++) {
		if (*it) {
			delete *it;
		}
	}
	icons_.clear();
}
void PlayerInfoFrame::InsertIcon(int index, Skill *skill){
	auto *icon = new SkillIcon(skill);
	icon->setPosition(Vec2(50+index*100, 50));
	icons_.push_back(icon);
	scrollview_->addChild(icon);
	return;
}
void PlayerInfoFrame::UpdateWithPlayerInfo(PlayerInfo *playerinfo) {
	string text = "Player Skill Point: " + to_string(playerinfo->get_point());
	label_point_->setString(text);
	return;
}
/* ============================================================
	Private
============================================================ */	
void PlayerInfoFrame::InitLabelPoint(int point){
	string text = "Player SKill Point: " + to_string(point);
	string font = "fonts/sdCrayon.ttf";
	int size = 24;
	label_point_ = Label::create(text, font, size);
	label_point_->setTextColor(Color4B(0, 0, 0, 255));
	label_point_->setPosition(Vec2(0, 130-size));
	this->addChild(label_point_);
	return;
}
void PlayerInfoFrame::InitScrollview(){
	int scrollview_height = 130;
	int scrollview_inner_width = 10*100;
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
	this->addChild(scrollview_);
	return;
}
void PlayerInfoFrame::InitIcons(){
	icons_.clear();
	return;
}