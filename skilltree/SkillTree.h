/* ============================================================
FileName: 	SkillTree.h
Revision: 	2016/09/07 by PorcaM
Modified: 	2016/10/05 by PorcaM
============================================================ */

#pragma once

#include <map>

#include "parts/Skill.h"
#include "skilltree/SkillNode.h"

/* ==================================================
	ClassName: 	SkillNode
	Modified: 	2016/10/05 by PorcaM

	Context:
		SkillTree is a learning network of skills. 
		It has each instance on each skill type(e.g. Heal, Buff, Debuff). 
		It is a tree, and element is a SkillNode. 
		SkillTree allocate new SkillNode. So This must free SkillNodes when destruction. 
================================================== */
class SkillTree{
 public:
 	typedef Skill::ID ID;
 	typedef Skill::Type Type;
 	typedef pair<int, SkillNode *> Pair;
 	typedef map<int, SkillNode *> Tree;
	~SkillTree();
	auto Begin()->Tree::iterator;
	auto End()->Tree::iterator;
	auto FindNode(ID id)->SkillNode*;
 protected:
	void InsertSkill(SkillNode *snode);
 private:
 	virtual void Init() = 0;
 	void Clear();
 	Tree tree_;
};