/* ============================================================
FileName: 	SkillTree.h
Revision: 	2016/09/07 by PorcaM
Modified: 	2016/09/27 by PorcaM
============================================================ */

#pragma once

#include <map>
#include "parts\Skill.h"
#include "skilltree\SkillNode.h"

typedef pair<int, SkillNode*> 			NodeType;
typedef map<int, SkillNode*>			TreeType;
typedef map<int, SkillNode*>::iterator	TreeIt;

class SkillTree{
 public:
	TreeType _tree; 	/* Key is Skill's ID. Value is Node for essential information */
	SkillTree ();
	~SkillTree ();
	void 		insertSkill (SkillNode*);
	SkillNode* 	findSkill (SkillID);
	void 		removeSkill (SkillID);
	int 		learnSkill (SkillID);
	TreeIt 		getBegin ();
	TreeIt 		getEnd ();
	void 		clear ();
	void InitWithType(Skill::Type type);
 private:
 	void InitHealSkillTree();
 	void InitBuffSkillTree();
 	void InitDebuffSkillTree();
};