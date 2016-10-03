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
 	PlayerInfoFrame(PlayerInfo *playerinfo);
 	~PlayerInfoFrame();
 	void set_playerinfo(PlayerInfo *playerinfo);
 	void UpdateWithPlayerInfo();
	void UpdateWithPlayerInfo(PlayerInfo *playerinfo);
 private:
 	void InitLabelPoint(int point);
 	void InitScrollview();
 	void InitIconList();
 	void InsertIcon(int index, Skill *skill);
 	Label *label_point_;
 	ui::ScrollView *scrollview_;
 	IconVec icon_list_;  // members in scroll
 	PlayerInfo *playerinfo_;
};