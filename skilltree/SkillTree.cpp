/* ============================================================
FileName: 	SkillTree.cpp
Revision: 	2016/09/07 by PorcaM
Modified: 	2016/09/27 by PorcaM
============================================================ */

#include "skilltree/SkillTree.h"

/* ==================================================
	Public
================================================== */
SkillTree::~SkillTree() {
	Clear();
}
auto SkillTree::Begin()->Tree::iterator{
	return tree_.begin();
}
auto SkillTree::End()->Tree::iterator{
	return tree_.end();
}
auto SkillTree::FindNode(ID id)->SkillNode*{
	SkillNode *snode = NULL;
	for (auto it = tree_.begin(); it != tree_.end(); ++it) {
		auto it_node = it->second;
		if (it_node->get_id() == id) {
			snode = it_node;
		}
	}
	if (snode == NULL) {
		assert(false);
	}
	return snode;
}
/* ==================================================
	Protected
================================================== */
void SkillTree::InsertSkill(SkillNode *snode){
	auto id = snode->get_id();
	if (tree_.find(id) != tree_.end()) {  // Redundancy
		assert(false);
	}
	tree_.insert(Pair(id, snode));
	return;
}
/* ==================================================
	Private
================================================== */
void SkillTree::Clear(){
	for (auto it = tree_.begin(); it != tree_.end(); ++it) {
		delete it->second;
	}
	tree_.clear();  // [CAUTION] I don't know this is necessary. 
	return;
}