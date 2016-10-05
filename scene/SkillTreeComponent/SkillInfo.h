/* ============================================================
FileName: 	SkillInfo.h
Revision: 	2016/09/22 by PorcaM
Modified: 	2016/10/05 by PorcaM
============================================================ */

#pragma once

#include "cocos2d.h"
#include "ui\CocosGUI.h"
USING_NS_CC;
#include "parts/Skill.h"
#include "skilltree/SkillTree.h"
#include "skillinstance/Factory/SkillFactory.h"
#include "skillinstance/Factory/HealSkillFactory.h"
#include "skillinstance/Factory/BuffSkillFactory.h"
#include "skillinstance/Factory/DebuffSkillFactory.h"
#include "skilltree/HealSkillTree.h"
#include "skilltree/BuffSkillTree.h"
#include "skilltree/DebuffSkillTree.h"

class SkillInfo{
 public:
 	SkillInfo();
 	~SkillInfo();
 	SkillFactory *get_factory_by_type(Skill::Type type);
 	SkillTree *get_skilltree_by_type(Skill::Type type);
 	auto RetrieveSkillByID(Skill::ID id)->Skill*;
 private:
 	SkillFactory **factory_arr_;
 	SkillTree **skilltree_arr_;
};