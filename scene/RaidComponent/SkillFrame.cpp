/*
FileName:	SkillFrame.cpp
Revision:	2016/08/30 by PorcaM
Modified:	2016/08/31 by PorcaM
*/
#include"../RaidScene.h"
#include "SkillFrame.h"
#include <string>
#include <cstdio>
#include "ConvertKorean.h"

SkillFrame::SkillFrame(Skill *skill) {
	_skill = skill;
	initBG();
	initLabel();
}

void SkillFrame::initBG() {
	string _path = "images/skillbg.png";
	_button = ui::Button::create(_path);
	_button->setScale9Enabled(true);
	_button->addTouchEventListener([](Ref *pSender, ui::Button::Widget::TouchEventType type) {
		ui::Button *btn = (ui::Button*)pSender;
		ui::ScrollView *scv = (ui::ScrollView*)(btn->getParent()->getParent());
		Raid *layer = (Raid*)scv->getParent();
		switch (type) {
		case ui::Button::Widget::TouchEventType::BEGAN:
			Raid::selectedNum = btn->getTag();
			CCLOG("selected %d", Raid::selectedNum);
			break;
		case ui::Button::Widget::TouchEventType::MOVED:
			break;
		case ui::Button::Widget::TouchEventType::ENDED:
			Raid::selectedNum = -1;
			break;
		}
	});
	_button->setSwallowTouches(false);
	return;
}

void SkillFrame::initLabel() {
	string _data = _skill->getName();
	_label = Label::createWithTTF(_AtoU8(_data.c_str()), "fonts/sdCrayon.ttf", 30);
	_label->setTextColor(Color4B(0, 0, 0, 255));
	_label->setWidth(60);
	_label->setAnchorPoint(Point(0.2, 0.3));
	_label->setPosition(_button->getSize().width / 2, _button->getSize().height / 2);
	_button->addChild(_label);
	return;
}