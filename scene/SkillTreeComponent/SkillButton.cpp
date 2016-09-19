/*
FileName:	SkillButton.cpp
Revision:	2016/09/12 by PorcaM
Modified: 	2016/09/19 by PorcaM
*/

#include "SkillButton.h"
#include <string>
#include <cstdio>
#include "ConvertKorean.h"
#include "scene/OHDialog.h"

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
		if (type == ui::Button::TouchEventType::ENDED){
			printf ("Skill Name is %s\n", _skill->getName ().c_str ());
			string title 	= "learn skill";
			string context 	= "learn this skill?\nor equip?";
			OHDialog dialog (Size (400, 250), title, context);
			dialog.okBtn -> addTouchEventListener ([] (Ref *pSender, ui::Button::Widget::TouchEventType type){
				/* OK button event */
			});
			dialog.addedTo (this);
			dialog.dialogContent->setPosition (Vec2 (0, 0));
		}
	});
	this->addChild (_button);
	return;
}

void SkillButton::initLabel (){
	string 	name = _skill->getName (); 		/* For code readability*/
	string 	font = "fonts/sdCrayon.ttf";
	int 	size = 24;
	_label = Label::create (_AtoU8 (name.c_str ()), font, size);
	_label->setAlignment (TextHAlignment::CENTER);
	_label->setTextColor (Color4B (0, 0, 0, 255));
	_label->setWidth (50);
	this->addChild (_label);
	return;
}