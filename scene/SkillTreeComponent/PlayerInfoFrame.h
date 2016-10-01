/* ============================================================
FileName: 	PlayerInfo.h
Revision: 	2016/10/01 by PorcaM
============================================================ */

#pragma once

#include <vector>
#include "cocos2d.h"
#include "ui\CocosGUI.h"
USING_NS_CC;
#include "scene/SkillTreeComponent/PlayerInfo.h"

class PlayerInfoFraem(){
 public:
 	PlayerInfoFrame();
 	~PlayerInfoFrame();
 	auto get_player_info();
 	void set_player_info(PlayerInfo *player_info);
 private:
 	PlayerInfo *player_info_;  // For player information structrue
 	
}