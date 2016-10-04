/* ============================================================
FileName: 	PlayerInfoFrame.h
Revision: 	2016/09/22 by PorcaM
Modified: 	2016/10/02 by PorcaM
============================================================ */

#pragma once

#include "cocos2d.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
#include "scene/SkillTreeComponent/SkillSlot.h"

class PlayerInfo{
 public:
 	PlayerInfo(int point, SkillSlot *slot);  // for saved data
 	~PlayerInfo();
 	auto get_point()->int;
 	auto get_slot()->SkillSlot*;
 	void AddPoint(int value);
 private:
 	void set_point(int point);
 	void set_slot(SkillSlot *slot);
 	int point_;
 	SkillSlot *slot_;
};