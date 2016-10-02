/* ============================================================
FileName: 	SkillIcon.h
Revision: 	2016/10/02 by PorcaM
Modified: 	2016/10/02 by PorcaM
============================================================ */

#include "scene/SkillTreeComponent/SkillIcon.h"

#include <string>
#include "ConvertKorean.h"

/* ============================================================
	Getter and Setter. 
============================================================ */
auto SkillIcon::get_skill()->Skill*{
	return skill_;
}
void SkillIcon::set_skill(Skill *skill){
	skill_ = skill;
	return;
}
auto SkillIcon::get_button()->ui::Button* {
	return button_;
}
/* ============================================================
	Public
============================================================ */
SkillIcon::SkillIcon(Skill *skill){
	set_skill(skill);
	InitLabel();
	InitButton();
}
SkillIcon::~SkillIcon(){
	delete label_;
	delete button_;
}
/* ============================================================
	Private
============================================================ */	
void SkillIcon::InitLabel(){
	string text = (skill_) ?
		get_skill()->getName():
		"Empty\nSkill";
	string font = "fonts/sdCrayon.ttf";
	int size = 24;
	label_ = Label::create(_AtoU8(text.c_str()), font, size);
	label_->setAlignment(TextHAlignment::CENTER);
	label_->setTextColor(Color4B (0, 0, 0, 255));
	label_->setWidth(50);
	this->addChild(label_);
	return;
}
void SkillIcon::InitButton(){
	string path = (skill_) ?
		"images/skilltree/icon_a.png":
		"images/skilltree/icon_e.png";
	button_ = ui::Button::create(path, path, path);
	this->addChild(button_);
	return;
}