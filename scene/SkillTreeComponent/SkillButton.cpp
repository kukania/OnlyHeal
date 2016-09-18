/*
FileName:	SkillButton.cpp
Revision:	2016/09/12 by PorcaM
*/

#include "SkillButton.h"
#include <string>
#include <cstdio>
#include "ConvertKorean.h"
#include "OHDialog.h"

SkillButton::SkillButton (Skill* skill){
	_skill = skill;
	initButton ();
	initLabel ();
}

SkillButton::~SkillButton (){
	delete _button;
	delete _label;
}

void SkillButton::initButton (){
	string sPath = "images/skilltree/icon_d.png";
	_button = ui::Button::create (sPath, sPath, sPath);
	_button->addTouchEventListener([&] (Ref *pSender, ui::Button::Widget::TouchEventType type) {
		printf ("Skill Name is %s\n", _skill->getName ().c_str ());
		OHDialog dialog (Size (400, 250), "Learn skill", "Learn this skill?");
		dialog.addedTo (this);
	});
	this->addChild (_button);
	return;
}

void SkillButton::initLabel (){
	string 	sText = _skill->getName ();
	string 	sFont = "fonts/sdCrayon.ttf";
	int 	iSize = 24;
	_label = Label::create (_AtoU8 (sText.c_str ()), sFont, iSize);
	_label->setAlignment (TextHAlignment::CENTER);
	_label->setTextColor (Color4B (0, 0, 0, 255));
	_label->setWidth (50);
	this->addChild (_label);
	return;
}