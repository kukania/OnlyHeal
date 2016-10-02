/* ==================================================
FileName:	SkillTreeFrame.h
Revision:	2016/09/12 by PorcaM
Modified: 	2016/10/02 by PorcaM
================================================== */

#pragma once

#include <vector>
#include "cocos2d.h"
#include "ui\CocosGUI.h"
USING_NS_CC;
#include "scene/SkillTreeComponent/PlayerInfo.h"
#include "scene/SkillTreeComponent/PlayerInfoFrame.h"
#include "scene/SkillTreeComponent/SkillIcon.h"
#include "scene/SkillTreeComponent/SkillInfo.h"
#include "skilltree/SkillTree.h"

class SkillTreeFrame : public CCNode{
 public:
 	typedef vector<SkillIcon*> IconVec;
 	SkillTreeFrame(SkillInfo *skillinfo, PlayerInfo *playerinfo, PlayerInfoFrame *playerinfoframe);
 	~SkillTreeFrame();
 	void set_skillinfo(SkillInfo *skillinfo);
 	void set_playerinfo(PlayerInfo *playerinfo);
	void set_playerinfoframe(PlayerInfoFrame *playerinfoframe);
 	void UpdateByType(Skill::Type type);
 private:
 	void InitScrollview();
 	void InitIconList();
 	void InsertIcon(SkillNode *node, SkillNode *prev);
 	void DrawFrame(SkillTree *skilltree);
 	void ClearFrame();
 	ui::ScrollView *scrollview_;
 	IconVec icon_list_;
 	SkillInfo *skillinfo_;
 	PlayerInfo *playerinfo_;
	PlayerInfoFrame *playerinfoframe_;
};