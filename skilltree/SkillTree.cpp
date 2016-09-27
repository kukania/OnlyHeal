/* ============================================================
FileName: 	SkillTree.cpp
Revision: 	2016/09/07 by PorcaM
Modified: 	2016/09/27 by PorcaM
============================================================ */

#include "SkillTree.h"

#include <cstdio>

SkillTree::SkillTree (){
	// No variable => nothing to do. 
}

/* clear all allocated nodes */
SkillTree::~SkillTree (){
	clear();  // Clear nodes of tree. 
}

void SkillTree::clear (){
	for (TreeIt ti = getBegin (); ti != getEnd (); ti++){
		delete ti->second;
	}
	_tree.clear ();
	return;
}

void 	SkillTree::insertSkill (SkillNode* node){
	if (_tree.find (node->getID ()) != _tree.end ()){
		printf ("Try to insert old-member skill!\n");
	}
	_tree.insert (NodeType (node->getID (), node));
	return;
}

SkillNode* 	SkillTree::findSkill (SkillID id){
	TreeIt ti;
	if ((ti = _tree.find (id)) == _tree.end ()){
		printf ("Try to find non-member skill!\n");
	}
	return ti->second;
}

void 	SkillTree::removeSkill (SkillID id){
	if (_tree.find (id) == _tree.end ()){
		printf ("Try to erase non-member skill!\n");
	}
	_tree.erase (id);
	return;
}

int 	SkillTree::learnSkill (SkillID id){
	SkillNode* skill = findSkill (id);
	SkillNode* prev = findSkill (skill->getPrev ());
	if (prev->getLearn ()){
		skill->setLearn (true);
		return 0;
	}
	else
		return 1;
}

TreeIt SkillTree::getBegin (){
	return _tree.begin ();
}

TreeIt SkillTree::getEnd (){
	return _tree.end ();
}

/* ============================================================
	Renewaled functions on 27th. 
============================================================ */
void SkillTree::InitWithType(Skill::Type type){
	if (type == kHeal) {
		InitHealSkillTree();
	} else if (type == kBuff) {
		InitBuffSkillTree();
	} else if (type == kDebuff) {
		InitDebuffSkillTree();
	} else {
		assert(false);
	}
	return;
}

void SkillTree::InitHealSkillTree(){
	clear();
	SkillNode *temp;
	insertSkill(new SkillNode (0, 0, true));
	insertSkill(temp = new SkillNode (1, 0, false));
	temp->set_col_n_row(0, 0);
	for (int i = 0; i < 6; i++){
		insertSkill(temp = new SkillNode (2+i, 1+i, false));
		temp->set_col_n_row(i+1, 1);
	}

	return;
}

void SkillTree::InitBuffSkillTree(){
	clear();
	return;
}

void SkillTree::InitDebuffSkillTree(){
	clear();
	return;
}