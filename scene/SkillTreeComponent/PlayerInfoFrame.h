/* ============================================================
FileName: 	PlayerInfoFrame.h
Revision: 	2016/10/01 by PorcaM
Modified: 	2016/10/01 by PorcaM
============================================================ */

#pragma once

#include <vector>
#include "cocos2d.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
#include "parts/Skill.h"
#include "scene/SkillTreeComponent/SkillIcon.h"

class PlayerInfoFrame : public CCNode{
 public:
 	typedef vector<SkillIcon *> Slot;
 	PlayerInfoFrame();
 	~PlayerInfoFrame();
 	auto get_label_point();
 	auto get_scrollview();
 	auto get_slot();
 	void InsertIcon(int index, Skill *skill);
 private:
 	void InitLabelPoint();
 	void InitScrollview();
 	void InitSlot();
 	Label *label_point_;
 	ui::ScrollView *scrollview_;
 	Slot slot_;  // members in scroll
};