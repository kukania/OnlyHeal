/* ============================================================
FileName:	SkillButton.cpp
Revision:	2016/09/12 by PorcaM
Modified: 	2016/09/27 by PorcaM

	1. Function Defintion ordering. 
		Because of return type of getter(auto), 
		getters must be defined fisrt. 
		At least, above of calling(using) getter. 
		In this file, getter and setter are first. 
============================================================ */

#include "scene\SkillTreeComponent\SkillButton.h"

#include <string>

#include "ConvertKorean.h"
#include "scene\OHDialog.h"

#define TOUCH_EVENT_LISTENER_PARM	Ref *pSender, ui::Button::Widget::TouchEventType type
#define GET_TOUCH_EVENT_TYPE		ui::Button::Widget::TouchEventType
/* ============================================================
	Getter and Setter. 
============================================================ */
auto SkillButton::get_belong_to(){
	return belong_to_;
}
void SkillButton::set_belong_to(BelongTo belong_to){
	belong_to_ = belong_to;
	return;
}
auto SkillButton::get_player_info(){
	return player_info_;
}
void SkillButton::set_player_info(PlayerInfo *player_info){
	if (player_info == NULL) {
		assert(false);
	}
	player_info_ = player_info;
	return;
}
auto SkillButton::get_label(){
	return label_;
}
void SkillButton::set_label(Label *label){
	if (label == NULL) {
		assert(false);
	}
	label_ = label;
}
auto SkillButton::get_button(){
	return button_;
}
void SkillButton::set_button(ui::Button *button){
	if (button == NULL) {
		assert(false);
	}
	button_ = button;
}
auto SkillButton::get_skill(){
	return skill_;
}
void SkillButton::set_skill(Skill *skill){
	if (skill == NULL) {
		assert(false);
	}
	skill_ = skill;
	return;
}
auto SkillButton::get_node(){
	return node_;
}
void SkillButton::set_node(SkillNode *node){
	if (node == NULL) {
		assert(false);
	}
	node_ = node;
	return;
}
auto SkillButton::get_prev(){
	return prev_;
}
void SkillButton::set_prev(SkillNode *prev){
	if (prev == NULL) {
		assert(false);
	}
	prev_ = prev;
	return;
}

/* ============================================================
	Public
============================================================ */
SkillButton::SkillButton(Skill *skill, SkillNode *node, SkillNode *prev){
	set_skill(skill);
	set_node(node);
	set_prev(prev);
	set_belong_to(kSkillTree);
	InitLabel();
	InitButton();
	setPosition(Vec2(node->get_col() * 100, node->get_row() * 100));
}
SkillButton::~SkillButton(){
	delete label_;
	delete button_;
}
void SkillButton::UpdateButton(){
	UpdateButtonTexture();
	UpdateButtonEvent();
}
void SkillButton::UpdateButtonTexture(){
	string color = (get_node()->getLearn ()) ? "a" : "d";
	string path = "images/skilltree/icon_" + color + ".png";
	get_button()->loadTextures (path, path, path);
	return;
}
void SkillButton::UpdateButtonEvent(){
	auto button = get_button();
	button->getEventDispatcher()->removeAllEventListeners();
	EventType type;
	if (get_belong_to() == kPlayerSlot) {
		type = kAlertDialogUnequip;
	} else if (get_node()->getLearn() == true) {
		type = kAlertDialogEquip;
	} else {
		type = kAlertDialogLearn;
	}
	AddEventListener(type);
	return;
}
void SkillButton::AddEventListener(EventType type){
	auto *button = get_button();
	std::function<void (TOUCH_EVENT_LISTENER_PARM)> callback;
	switch (type) {
	case kAlertDialogLearn: {
		callback = [=](TOUCH_EVENT_LISTENER_PARM) {
			if (type == GET_TOUCH_EVENT_TYPE::ENDED) {
				string title = "LEARN_SKILL";
				string prompt = "Do you want to learn this skill?\n";
				string info = "SkillName: " + get_skill()->getName();
				OHDialog dialog(Size(400, 250), title, prompt + info);
				dialog.okBtn->addTouchEventListener([=](TOUCH_EVENT_LISTENER_PARM) {
					if (type == GET_TOUCH_EVENT_TYPE::ENDED) {
						auto learn = get_prev()->getLearn();
						auto point = get_player_info()->get_point();
						auto need = 5;
						if (learn == true && point > need) {
							get_node()->setLearn(true);
							get_player_info()->set_point(point - need);
							printf("Success learn!\n");
						} else {
							printf("Fail to learn!\n");
						}
						UpdateButton();
						((CCNode*)pSender)->getParent()->removeFromParent();
					}
				});
				dialog.addedTo(Director::getInstance()->getRunningScene());
			}
		};
		break;
	}
	case kAlertDialogEquip: {
		callback = [=](TOUCH_EVENT_LISTENER_PARM) {
			if (type == GET_TOUCH_EVENT_TYPE::ENDED) {
				string title = "EQUIP SKILL";
				string prompt = "Do you want to equip this skill?\n";
				string info = "SkillName: " + get_skill()->getName();
				OHDialog dialog(Size(400, 250), title, prompt + info);
				dialog.okBtn->addTouchEventListener([=](TOUCH_EVENT_LISTENER_PARM) {
					if (type == GET_TOUCH_EVENT_TYPE::ENDED) {
						if (true) {
							// equip skill
						} else {
							printf("Fail to equip\n");
						}
						UpdateButton();
						((CCNode*)pSender)->getParent()->removeFromParent();
					}
				});
				dialog.addedTo(Director::getInstance()->getRunningScene());
			}
		};
		break;
	}
	case kAlertDialogUnequip: {
		callback = [=](TOUCH_EVENT_LISTENER_PARM) {
			if (type == GET_TOUCH_EVENT_TYPE::ENDED) {
				string title = "UNEQUIP_SKILL";
				string prompt = "Do you want to unequip this skill?\n";
				string info = "SkillName: " + get_skill()->getName();
				OHDialog dialog(Size(400, 250), title, prompt + info);
				dialog.okBtn->addTouchEventListener([=](TOUCH_EVENT_LISTENER_PARM) {
					if (type == GET_TOUCH_EVENT_TYPE::ENDED) {
						if (true) {
							// unequip skill
						} else {
							printf("Fail to unequip\n");
						}
						UpdateButton();
						((CCNode*)pSender)->getParent()->removeFromParent();
					}
				});
				dialog.addedTo(Director::getInstance()->getRunningScene());
			}
		};
		break;
	}
	default: {
		assert(false);
		break;
	}
	}
	button->addTouchEventListener(callback);
	return;
}
/* ============================================================
	Private
============================================================ */
void SkillButton::InitLabel(){
	string text = get_skill()->getName();
	string font = "fonts/sdCrayon.ttf";
	int size = 24;
	set_label(Label::create(_AtoU8(text.c_str()), font, size));
	auto label = get_label();
	label->setAlignment(TextHAlignment::CENTER);
	label->setTextColor(Color4B (0, 0, 0, 255));
	label->setWidth(50);
	this->addChild(label);
	return;
}
void SkillButton::InitButton(){
	set_button(ui::Button::create());
	auto button = get_button();
	UpdateButtonTexture();  /* MUST be called after allocation! */
	//UpdateButtonEvent();
	this->addChild(button);
	return;
}

#undef TOUCH_EVENT_LISTENER_PARM