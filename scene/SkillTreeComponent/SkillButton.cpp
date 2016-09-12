/*
FileName:	SkillButton.cpp
Revision:	2016/09/12 by PorcaM
*/

#include "SkillButton.h"
#include <string>

SkillButton::SkillButton (Skill* skill){
	_skill = skill;
	initButton ();
	initLabel ();
}

SkillButton::~SkillButton (){

}

void SkillButton::initButton (){
	string sPath = "images/skilltree/icon_d.png";
	_button = ui::Button::create (sPath, sPath, sPath);
	_button->addTouchEventListener([] (Ref *pSender, ui::Button::Widget::TouchEventType type) {
		pritnf ("I do nothing\n");
	});
	this->addChild (_button);
	return;
}

void SkillButton::initLabel (){
	string 	sText = _skill->getName ();
	string 	sFont = "fonts/sdCrayon.ttf";
	int 	iSize = 24;
	_label = Label::create (sText, sFont, iSize);
	this->addChild (_label);
	return;
}