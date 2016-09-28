/* ============================================================
FileName:	SkillButton.cpp
Revision:	2016/09/12 by PorcaM
Modified: 	2016/09/27 by PorcaM
============================================================ */

#include "scene\SkillTreeComponent\SkillButton.h"

SkillButton::SkillButton(Skill *skill, SkillNode *node, SkillNode *prev){

}
SkillButton::~SkillButton(){

}
auto SkillButton::get_label(){
	return label_;
}/*
void SkillButton::set_label();
auto SkillButton::get_button();
void SkillButton::set_button();
auto SkillButton::get_skill();
void SkillButton::set_skill();
auto SkillButton::get_node();
void SkillButton::set_node();
auto SkillButton::get_prev();
void SkillButton::set_prev();*/

// #include <string>
// #include <cstdio>

// #include "ConvertKorean.h"
// #include "scene\OHDialog.h"

// #define TOUCH_END(type) type == ui::Button::TouchEventType::ENDED
// #define TEL_PARAM 		Ref *pSender, ui::Button::Widget::TouchEventType type

// SkillButton::SkillButton (Skill* skill, SkillNode* node, SkillNode* prev){
// 	_skill = skill;
// 	_node = node;
// 	_prev = prev;
// 	initButton ();
// 	initLabel ();
// 	setPosition(Vec2(node->get_col()*100, node->get_row()*100));
// }

// SkillButton::~SkillButton (){
// 	CC_SAFE_DELETE(button_);
// 	CC_SAFE_DELETE(label_);
// 	delete _button;
// 	delete _label;
// }

// void 
// SkillButton::
// initButton (){
// 	_button = ui::Button::create ();
// 	updateButton();
// 	_button->addTouchEventListener([&](TEL_PARAM) {
// 		if (TOUCH_END(type)){
// 			bool	learn 	= _node -> getLearn ();
// 			string 	title	= learn?
// 							"EQUIP_SKILL":
// 							"LEARN_SKILL";
// 			string	prompt	= learn?
// 							"equip this skill?\n":
// 							"learn this skill?\n";
// 			string	info 	= "SkillName: " + _skill -> getName () + "\n" +	"SkillID: " + "\n";
// 			OHDialog dialog (Size (400, 250), title, prompt + info);
// 			dialog.okBtn -> addTouchEventListener ([=](TEL_PARAM) {
// 				if (TOUCH_END(type)){
// 					if (_prev -> getLearn () == true && true){
// 						/* learn, point */
// 						_node -> setLearn (true);
// 					}
// 					else{
// 						printf ("Fail to learn!\n");
// 					}
// 					updateButton ();
// 					((CCNode*)pSender) -> getParent () -> removeFromParent ();
// 				}
// 			});
// 			dialog.addedTo (Director::getInstance () -> getRunningScene ());
// 		}
// 	});
// 	this->addChild (_button);
// 	return;
// }

// void SkillButton::initLabel (){
// 	string 	name = _skill->getName (); 		/* For code readability */
// 	string 	font = "fonts/sdCrayon.ttf";
// 	int 	size = 24;
// 	_label = Label::create (_AtoU8 (name.c_str ()), font, size);
// 	_label->setAlignment (TextHAlignment::CENTER);
// 	_label->setTextColor (Color4B (0, 0, 0, 255));
// 	_label->setWidth (50);
// 	this->addChild (_label);
// 	return;
// }

// void SkillButton::updateButton (){
// 	string color = (_node->getLearn ()) ? "a" : "d";
// 	string path = "images/skilltree/icon_" + color + ".png";
// 	_button->loadTextures (path, path, path);
// 	return;
// }

// #undef TOUCH_END
// #undef TEL_PARAM