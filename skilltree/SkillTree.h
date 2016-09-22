/*
FileName: 	SkillTree.h
Revision: 	2016/09/07 by PorcaM
Modified: 	2016/09/22 by PorcaM
*/

#pragma once
#include "SkillNode.h"
#include <map>

typedef pair<int, SkillNode*> 			NodeType;
typedef map<int, SkillNode*>			TreeType;
typedef map<int, SkillNode*>::iterator	TreeIt;

class SkillTree{
private:
	unsigned int 	_point;
public:
	TreeType _tree; 	/* Key is Skill's ID. Value is Node for essential information */
	SkillTree ();
	~SkillTree ();
	void 			setPoint (unsigned int);
	unsigned int 	getPoint ();
	void 		insertSkill (SkillNode*);
	SkillNode* 	findSkill (SkillID);
	void 		removeSkill (SkillID);
	void 		initHealSkillTree ();
	void 		initBuffSkillTree ();
	int 		learnSkill (SkillID);
	TreeIt 		getBegin ();
	TreeIt 		getEnd ();
	void 		clear ();
};