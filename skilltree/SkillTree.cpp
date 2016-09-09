/*
FileName: 	SkillTree.cpp
Revision: 	2016/09/07 by PorcaM
Modified: 	2016/09/09 by PorcaM
*/

#include "SkillTree.h"
#include <cstdio>

SkillTree::SkillTree (){
	_tree.clear ();
}

SkillTree::~SkillTree (){
	for (TreeIt ti = _tree.begin ();
		ti != _tree.end (); ti++){
		delete ti->second;
	}
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

void 	SkillTree::initHealSkillTree (){
	insertSkill (new SkillNode (0, 0, true));
	insertSkill (new SkillNode (1, 0, false));

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