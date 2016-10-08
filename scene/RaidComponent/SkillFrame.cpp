/* ==================================================
FileName:	SkillFrame.cpp
Revision:	2016/08/30 by PorcaM
Modified:	2016/10/08 by PorcaM
================================================== */
#include "scene/RaidComponent/SkillFrame.h"

#include <string>
#include <cstdio>
#include"../RaidScene.h"
#include "ConvertKorean.h"

SkillFrame::SkillFrame(string name) {
	name_ = name;
	initBG();
	initLabel();
}

void SkillFrame::initBG() {
	string _path = "images/raid/skillbg.png";
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
	string text = name_;
	string font = "fonts/sdCrayon.ttf";
	int size = 30;
	_label = Label::createWithTTF(_AtoU8(text.c_str()), font, size);
	_label->setTextColor(Color4B(0, 0, 0, 255));
	_label->setWidth(60);
	_label->setAnchorPoint(Point(0.2, 0.3));
	_label->setPosition(_button->getSize().width / 2, _button->getSize().height / 2);
	_button->addChild(_label);
	return;
}