/*
FileName:	SkillFrame.cpp
Revision:	2016/08/30 by PorcaM
Modified:	2016/08/31 by PorcaM
*/

#include "SkillFrame.h"
#include <string>

SkillFrame::SkillFrame(Skill *skill) {
	_skill = skill;
	initBG();
	initLabel();
}

void SkillFrame::initBG() {
	string _path = "images/bg.png";
	_bg = Sprite::create(_path);
	this->addChild(_bg);
	return;
}

void SkillFrame::initLabel() {
	string _data = _skill->getName();
	_label = Label::create(_data, "fonts/arial.ttf", 24);
	this->addChild(_label);
	return;
}