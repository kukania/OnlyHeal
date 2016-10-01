/* ============================================================
FileName: 	PlayerInfoFrame.h
Revision: 	2016/09/22 by PorcaM
Modified: 	2016/10/02 by PorcaM
============================================================ */

#pragma once

#include <vector>
#include "cocos2d.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
#include "parts/Skill.h"  /* Perhaps this Lib is not essential. */

class PlayerInfo{
 public:
 	PlayerInfo();
 	~PlayerInfo();
 	auto get_point();
 	auto get_slot();
 	void AddPoint(int value);
 private:
 	void set_point(int point);
 	int point_;
 	Slot slot_;
}