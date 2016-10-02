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
#include "scene/SkillTreeComponent/PlayerInfo.h"

class PlayerInfoFrame : public CCNode{
 public:
 	typedef vector<SkillIcon *> IconVec;
 	PlayerInfoFrame();
 	PlayerInfoFrame(PlayerInfo *player_info);
 	~PlayerInfoFrame();
 	auto get_label_point();
 	auto get_scrollview();
 	auto get_icons();
 	void InsertIcon(int index, Skill *skill);
 private:
 	void InitLabelPoint(int point);
 	void InitScrollview();
 	void InitIcons();
 	Label *label_point_;
 	ui::ScrollView *scrollview_;
 	IconVec icons_;  // members in scroll
};