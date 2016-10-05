/* ============================================================
FileName: 	HealSkillTree.cpp
Revision: 	2016/10/05 by PorcaM
Modified: 	2016/10/05 by PorcaM
============================================================ */

#include "skilltree/HealSkillTree.h"

virtual void HealSkillTree::Init() {
	clear();
	SkillNode *temp;
	insertSkill(new SkillNode(0, 0, true));
	insertSkill(temp = new SkillNode(1, 0, false));
	temp->set_col_row(0, 0);
	insertSkill(temp = new SkillNode(8, 1, false));
	temp->set_col_row(0, 1);
	insertSkill(temp = new SkillNode(15, 1, false));
	temp->set_col_row(0, 2);
	for (int i = 0; i < 6; ++i) {  // from 2 to 7
		insertSkill(temp = new SkillNode(2 + i, 1 + i, false));
		temp->set_col_row(i + 1, 0);
	}
	for (int i = 0; i < 6; ++i) {  // from 9 to 14
		insertSkill(temp = new SkillNode(9 + i, 8 + i, false));
		temp->set_col_row(i + 1, 1);
	}
	for (int i = 0; i < 6; ++i) {  // from 16 to 21
		insertSkill(temp = new SkillNode(16 + i, 8 + i, false));
		temp->set_col_row(i + 1, 2);
	}
	return;
}