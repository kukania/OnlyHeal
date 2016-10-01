/* ============================================================
FileName:	SkillButton.h
Revision:	2016/09/12 by PorcaM
Modified: 	2016/09/28 by PorcaM

SkillButton is in SkillTreeFrame. 
This is a instance of that. 
Instance means individual skill. 
Functions
	1. Show information to user
		Information about skill
		e.g. skill usability, Learning net, 
	2. Update Skilltree
		Learn skill. 
	3. Update SkillSet
		Equipment skill. 
============================================================ */

#pragma once

#include "cocos2d.h"
#include "ui\CocosGUI.h"
USING_NS_CC;
#include "parts\Skill.h"
#include "scene/SkillTreeComponent/PlayerInfo.h"
#include "skilltree\SkillTree.h"

/* ============================================================
	This class has own members: label, button. 
	Just view(never edit or delete) members: skill, node, prev. 
============================================================ */
class SkillButton : public CCNode{
 public:
 	typedef void EventListener(Ref *pSender, ui::Button::Widget::TouchEventType type);
 	enum EventType{
 		kAlertDialogLearn = 0,
 		kAlertDialogEquip,
 		kAlertDialogUnequip
 	};
 	enum BelongTo{
 		kSkillTree = 0,
 		kPlayerSlot
 	};
	SkillButton (Skill *skill, SkillNode *node, SkillNode *prev);
	~SkillButton ();
	auto get_belong_to();
	void set_belong_to(BelongTo belong_to);
	auto get_player_info();
	void set_player_info(PlayerInfo *player_info);
	auto get_label();
	auto get_button();
	auto get_skill();
	void set_skill(Skill *skill);
	auto get_node();
	void set_node(SkillNode *node);
	auto get_prev();
	void set_prev(SkillNode *prev);
	void UpdateButton();
	void UpdateButtonTexture();
	void UpdateButtonEvent();
	void AddEventListener(EventType type);
 private:
 	void InitLabel();
 	void InitButton();
 	Label *label_;
 	ui::Button *button_;
	Skill *skill_;
	SkillNode *node_, *prev_;
	PlayerInfo *player_info_;
	BelongTo belong_to_;
};