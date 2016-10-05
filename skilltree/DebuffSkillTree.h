/* ============================================================
FileName: 	DebuffSkillTree.h
Revision: 	2016/10/05 by PorcaM
Modified: 	2016/10/05 by PorcaM
============================================================ */

#pragma once

#include "skilltree/SkillTree.h"

/* ==================================================
	ClassName: 	DebuffSkillTree
	Modified: 	2016/10/05 by PorcaM
================================================== */
class DebuffSkillTree : public SkillTree{
 public:
	DebuffSkillTree();
 private:
 	virtual void Init() = 0;
};