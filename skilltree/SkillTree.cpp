/* ============================================================
FileName: 	SkillTree.cpp
Revision: 	2016/09/07 by PorcaM
Modified: 	2016/09/27 by PorcaM
============================================================ */

#include "skilltree/SkillTree.h"

/* ==================================================
	Public
================================================== */
SkillTree::SkillTree() {
	Init();
}
SkillTree::~SkillTree() {
	Clear();
}
void SkillTree::InitHealSkillTree() {
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
void SkillTree::InsertSkill(SkillNode *snode){
	auto id = snode->get_id();
	if (tree_.find(id) != tree_.end()) {  // Redundancy
		assert(false);
	}
	tree_.insert(NodeType(id, snode));
	return;
}
void SkillTree::Clear(){
	for (auto it = tree_.begin(); it != tree_.end(); ++it) {
		delete it->second;
	}
	tree_.clear();  // [CAUTION] I don't know this is necessary. 
	return;
}