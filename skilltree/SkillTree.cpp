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
	_tree.insert (NodeType (node->getID (), node));
	return;
}

SkillNode* 	SkillTree::findSkill (SkillID id){
	return _tree.find (id)->second;
}

void 	SkillTree::removeSkill (SkillID id){
	if (_tree.find (id) == _tree.end ()){
		printf ("Try to erase non-member skill!\n");
	}
	_tree.erase (id);
	return;
}