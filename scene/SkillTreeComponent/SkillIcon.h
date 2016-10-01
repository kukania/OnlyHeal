/* ============================================================
FileName: 	SkillIcon.h
Revision: 	2016/10/02 by PorcaM
Modified: 	2016/10/02 by PorcaM
============================================================ */

#pragma once

#include <vector>
#include "cocos2d.h"
#include "ui/CocosGUI.h"
USING_NS_CC;

class SkillIcon : public CCNode{
 public:
 	SkillIcon();
 	~SkillIcon();
 private:
 	void InitLabelPoint();
 	void InitScrollview();
 	void InitSlot();
 	Label *label_point_;
 	ui::ScrollView *scrollview_;
 	Slot slot_;  // members in scroll
}