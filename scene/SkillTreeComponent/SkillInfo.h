/* ============================================================
FileName: 	SkillInfo.h
Revision: 	2016/09/22 by PorcaM
Modified: 	2016/10/05 by PorcaM
============================================================ */

#pragma once

#include <vector>

#include "cocos2d.h"
#include "ui\CocosGUI.h"
USING_NS_CC;
#include "parts/Skill.h"
#include "skillinstance/Factory/SkillFactory.h"
#include "skillinstance/Factory/HealSkillFactory.h"
#include "skillinstance/Factory/BuffSkillFactory.h"
#include "skillinstance/Factory/DebuffSkillFactory.h"
#include "skilltree/SkillTree.h"
#include "skilltree/HealSkillTree.h"
#include "skilltree/BuffSkillTree.h"
#include "skilltree/DebuffSkillTree.h"

class SkillInfo{
 public:
 	typedef Skill::ID ID;
 	typedef Skill::Type Type;
 	typedef vector<SkillFactory*> FactoryVec;
 	typedef vector<SkillTree*> SkilltreeVec;
 	SkillInfo();
 	~SkillInfo();
 	auto get_factory_by_type(Type type)->SkillFactory *;
 	auto get_skilltree_by_type(Type type)->SkillTree *;
 	auto RetrieveSkillByID(ID id)->Skill*;
 private:
 	void InitFactoryList();
 	void ClearFactoryList();
 	void InitSkilltreeList();
 	void ClearSkilltreeList();
 	FactoryVec factory_list_;
 	SkilltreeVec skilltree_list_;
 	SkillFactory **factory_arr_;
 	SkillTree **skilltree_arr_;
};