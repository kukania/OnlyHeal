/*
FileName:	SkillFrame.cpp
Revision:	2016/08/30 by PorcaM
Modified:	2016/08/31 by PorcaM
*/

#include "SkillFrame.h"
#include <string>
#include <cstdio>

SkillFrame::SkillFrame(Skill *skill) {
	_skill = skill;
	initBG();
	initLabel();
}

void SkillFrame::initBG() {
	string _path = "images/skillbg.png";
	_button = ui::Button::create(_path);
	_button->addTouchEventListener([](Ref *sender, ui::Button::Widget::TouchEventType type) {
		printf("button is touched!\n");
	});
	this->addChild(_button);
	return;
}

void SkillFrame::initLabel() {
	string _data = _skill->getName();
	_label = Label::create(_data, "fonts/arial.ttf", 24);
	_label->setTextColor(Color4B(0, 0, 0, 255));
	this->addChild(_label);
	return;
}