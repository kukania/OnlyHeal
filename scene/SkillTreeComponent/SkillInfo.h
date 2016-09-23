/* ============================================================
FileName: 	SkillInfo.h
Revision: 	2016/09/22 by PorcaM

SkillInfo is in SkillTreeScene. 
This class has information about SkillTree. 
This class has two (important) component. 
	1. SkillFactory
		Give exact information about skill. 
		e.g. Name, ID, etc
	2. SkillTree
		Give relative information about skills and skilltree. 
		e.g. Learning net, cost, etc 
============================================================ */

#pragma once

#include "skilltree/SkillTree.h"
#include "skillinstance/Factory/HealSkillFactory.h"
#include "skillinstance/Factory/BuffSkillFactory.h"
#include "skillinstance/Factory/DebuffSkillFactory.h"

#include "cocos2d.h"
#include "ui\CocosGUI.h"
USING_NS_CC;

class SkillInfo{

};