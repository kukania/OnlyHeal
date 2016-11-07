/* ============================================================
   FileName:    BuffSkillTree.cpp
   Revision:    2016/10/05 by PorcaM
   Modified:    2016/11/07 by PorcaM
   ============================================================ */

#include "skilltree/BuffSkillTree.h"

BuffSkillTree::BuffSkillTree() {
	Init();
	offset_ = 50;
}

void BuffSkillTree::Init() {
	SkillNode* temp;

	InsertSkill(new SkillNode(0, 0, true));
	InsertSkill(temp = new SkillNode(51, 0, false));
	temp->set_col_row(0, 0);
	return;
}
