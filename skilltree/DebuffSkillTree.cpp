/* ============================================================
   FileName:    DebuffSkillTree.cpp
   Revision:    2016/10/05 by PorcaM
   Modified:    2016/11/07 by PorcaM
   ============================================================ */

#include "skilltree/DebuffSkillTree.h"

DebuffSkillTree::DebuffSkillTree() {
	Init();
	offset_ = 100;
}

void DebuffSkillTree::Init() {
	SkillNode* temp;

	InsertSkill(new SkillNode(0, 0, true));
	InsertSkill(temp = new SkillNode(101, 0, false));
	temp->set_col_row(0, 0);
	return;
}
