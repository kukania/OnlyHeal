/*
FileName:	SkillTreeFrame.h
Revision:	2016/09/12 by PorcaM
*/

#pragma once

#include "cocos2d.h"
#include "ui\CocosGUI.h"
#include "parts\Skill.h"
#include "skilltree\SkillTree.h"
#include "SkillButton.h"
USING_NS_CC;

class SkillTreeFrame{
private:
	SkillButton* pSbv;
public:
	SkillTreeFrame (SkillTree*);
	void initButton ();
};