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
auto SkillButton::get_type(){
	return type_;
}
void SkillButton::set_type(Type type){
	type_ = type;
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
auto SkillButton::get_callback(){
	return callback_;
}
void SkillButton::set_callback(ui::Button::Widget::ccWidgetTouchCallback callback){
	callback_ = callback;
}

/* ============================================================
	Public
============================================================ */
SkillButton::SkillButton(Skill *skill, SkillNode *node, SkillNode *prev, Type type){
	set_skill(skill);
	set_node(node);
	set_prev(prev);
	set_type(type);
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
	//UpdateButtonCallback();
}
void SkillButton::UpdateButtonTexture(){
	string color = (get_node()->getLearn ()) ? "a" : "d";
	string path = "images/skilltree/icon_" + color + ".png";
	get_button()->loadTextures(path, path, path);
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
	UpdateButtonTexture();
	Type type = get_type();
	if (type == kNotLearned) {
		CallbackLearn();
	} else if (type == kLearned) {
		CallbackEquip();
	} else if (type == kEquiped) {
		CallbackUnequip();
	} else {
		assert(false);
	}
	button->addTouchEventListener(get_callback());
	this->addChild(button);
	return;
}
void SkillButton::CallbackLearn(){
	set_callback([=](Ref *pSender, ui::Button::Widget::TouchEventType type) {
		if (type == ui::Button::Widget::TouchEventType::ENDED) {
			string title = "LEARN_SKILL";
			string prompt = "Do you want to learn this skill?\n";
			string info = "SkillName: " + get_skill()->getName();
			OHDialog dialog(Size(400, 250), title, prompt + info);
			dialog.okBtn->addTouchEventListener([=](Ref *pSender, ui::Button::Widget::TouchEventType type) {
				if (type == ui::Button::Widget::TouchEventType::ENDED) {
					auto learn = get_prev()->getLearn();
					auto point = get_player_info()->get_point();
					auto need = 5;
					if (learn == false) {
						printf("Learn prev skill first!\n");
					} else if (point < need) {
						printf("No point\n");
					} else {
						get_node()->setLearn(true);
						get_player_info()->set_point(point - need);
						UpdateButtonTexture();
						printf("Success learn!\n");
					}
					((CCNode*)pSender)->getParent()->removeFromParent();
				}
			});
			dialog.addedTo(Director::getInstance()->getRunningScene());
		}
	});
}

void SkillButton::CallbackEquip(){
	set_callback([=](Ref *pSender, ui::Button::Widget::TouchEventType type) {
		if (type == ui::Button::Widget::TouchEventType::ENDED) {
			string title = "EQUIP SKILL";
				string prompt = "Do you want to equip this skill?\n";
				string info = "SkillName: " + get_skill()->getName();
				OHDialog dialog(Size(400, 250), title, prompt + info);
				dialog.okBtn->addTouchEventListener([=](Ref *pSender, ui::Button::Widget::TouchEventType type) {
					if (type == ui::Button::Widget::TouchEventType::ENDED) {
						if (true) {
							// equip skill
						} else {
							printf("Fail to equip\n");
						}
						((CCNode*)pSender)->getParent()->removeFromParent();
					}
				});
				dialog.addedTo(Director::getInstance()->getRunningScene());
		}
	});
}

void SkillButton::CallbackUnequip(){
	set_callback([=](Ref *pSender, ui::Button::Widget::TouchEventType type) {
		if (type == ui::Button::Widget::TouchEventType::ENDED) {
			string title = "UNEQUIP SKILL";
				string prompt = "Do you want to unequip this skill?\n";
				string info = "SkillName: " + get_skill()->getName();
				OHDialog dialog(Size(400, 250), title, prompt + info);
				dialog.okBtn->addTouchEventListener([=](Ref *pSender, ui::Button::Widget::TouchEventType type) {
					if (type == ui::Button::Widget::TouchEventType::ENDED) {
						if (true) {
							// unequip skill
						} else {
							printf("Fail to equip\n");
						}
						((CCNode*)pSender)->getParent()->removeFromParent();
					}
				});
				dialog.addedTo(Director::getInstance()->getRunningScene());
		}
	});
}


#undef TOUCH_EVENT_LISTENER_PARM