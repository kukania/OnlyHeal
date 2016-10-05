/* ============================================================
FileName: 	SkillSlot.h
Revision: 	2016/10/02 by PorcaM
Modified: 	2016/10/02 by PorcaM
============================================================ */

#pragma once

#include <vector>
#include "cocos2d.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
#include "parts/Skill.h"

class SkillSlot{
 public:
 	typedef vector<Skill *> SkillVec;
 	const int kMaxSlotNum = 10;
 	SkillSlot();
 	~SkillSlot();
 	int Size();
 	auto Begin();
 	auto End();
 	void InsertSkill(Skill *skill);
 	void RemoveSkill(int index);
 	void RemoveSkill(SkillVec::iterator it);
	auto FindSkillWithIndex(int index)->SkillVec::iterator;
 	auto FindSkillWithSkill(Skill *skill);
	void Assign(SkillVec sv);
	auto get_list()->SkillVec;
 private:
 	SkillVec list_;
};