/* ============================================================
FileName: 	HealSkillTree.h
Revision: 	2016/10/05 by PorcaM
Modified: 	2016/10/05 by PorcaM
============================================================ */

#pragma once

#include "skilltree/SkillTree.h"

/* ==================================================
	ClassName: 	HealSkillTree
	Modified: 	2016/10/05 by PorcaM
================================================== */
class HealSkillTree : public SkillTree{
 public:
	HealSkillTree();
 private:
 	virtual void Init();
};