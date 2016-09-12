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
#include <vector>
USING_NS_CC;

class SkillTreeFrame{
private:
	vector<SkillButton*> sbv;
public:
	SkillTreeFrame (SkillTree*);
	~SkillTreeFrame ();
	void insertButton (Skill*);
};