/* ============================================================
FileName: 	BuffSkillTree.h
Revision: 	2016/10/05 by PorcaM
Modified: 	2016/10/05 by PorcaM
============================================================ */

#pragma once

#include "skilltree/SkillTree.h"

/* ==================================================
	ClassName: 	BuffSkillTree
	Modified: 	2016/10/05 by PorcaM
================================================== */
class BuffSkillTree : public SkillTree{
 public:
	BuffSkillTree();
 private:
 	virtual void Init();
};