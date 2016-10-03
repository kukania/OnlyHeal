/* ============================================================
FileName: 	PlayerInfoFrame.cpp
Revision: 	2016/10/01 by PorcaM
Modified: 	2016/10/01 by PorcaM
============================================================ */

#include "scene/SkillTreeComponent/PlayerInfoFrame.h"

#include <string>
#include "scene/OHDialog.h"

/* ============================================================
	Getter and Setter. 
============================================================ */
void PlayerInfoFrame::set_playerinfo(PlayerInfo *playerinfo){
	if (playerinfo == NULL) {
		assert(false);
	}
	playerinfo_ = playerinfo;
	return;
}
/* ============================================================
	Public
============================================================ */
PlayerInfoFrame::PlayerInfoFrame(){
	InitLabelPoint(0);
 	InitScrollview();
	InitIconList();
 	for (int i = 0; i < 10; ++i) {
 		InsertIcon(i, NULL);
 	}
}
PlayerInfoFrame::PlayerInfoFrame(PlayerInfo *playerinfo){
	set_playerinfo(playerinfo);
	InitLabelPoint(playerinfo_->get_point());
	InitScrollview();
	InitIconList();
	auto slot = playerinfo_->get_slot();
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
	for (auto it = icon_list_.begin(); it != icon_list_.end(); it++) {
		if (*it) {
			delete *it;
		}
	}
	icon_list_.clear();
}
void PlayerInfoFrame::UpdateWithPlayerInfo() {
	string text = "Player Skill Point: " + to_string(playerinfo_->get_point());
	label_point_->setString(text);
	scrollview_->removeAllChildren();
	icon_list_.clear();
	auto slot = playerinfo_->get_slot();
	int i;
	for (i = 0; i < slot->Size(); ++i) {
		InsertIcon(i, *(slot->FindSkillWithIndex(i)));
	}
	for (; i < 10; ++i) {
		InsertIcon(i, NULL);
	}
	return;
}
void PlayerInfoFrame::UpdateWithPlayerInfo(PlayerInfo *playerinfo) {
	set_playerinfo(playerinfo);
	UpdateWithPlayerInfo();
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
void PlayerInfoFrame::InitIconList(){
	icon_list_.clear();
	return;
}
void PlayerInfoFrame::InsertIcon(int index, Skill *skill){
	auto *icon = new SkillIcon(skill);
	icon->setPosition(Vec2(50+index*100, 50));
	icon->get_button()->addTouchEventListener([=](
			Ref *pSender,
			ui::Button::Widget::TouchEventType type){
		auto slot = playerinfo_->get_slot();
		if (type == ui::Button::Widget::TouchEventType::ENDED) {
			string title = "UNEQUIP_SKILL";
			string prompt = "Do you want to unequip this skill?\n";
			string info = "Skill Name: " + skill->getName();
			OHDialog dialog(Size(400, 250), title, prompt+info);
			dialog.okBtn->addTouchEventListener([=](
					Ref *pSender,
					ui::Button::Widget::TouchEventType type){
				if (type == ui::Button::Widget::TouchEventType::ENDED) {
					slot->RemoveSkill(index);
				}
			});
			dialog.addedTo(Director::getInstance()->getRunningScene());
		}
	});
	icon_list_.push_back(icon);
	scrollview_->addChild(icon);
	return;
}