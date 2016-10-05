/* ============================================================
FileName: 	HealSkillTree.h
Revision: 	2016/10/05 by PorcaM
Modified: 	2016/10/05 by PorcaM
============================================================ */

#pragma once

#include <map>

#include "parts/Skill.h"
#include "skilltree/SkillNode.h"
#include "skilltree/SkillTree.h"

/* ==================================================
	ClassName: 	HealSkillTree
	Modified: 	2016/10/05 by PorcaM

	Context:
		SkillTree is a learning network of skills. 
		It has each instance on each skill type(e.g. Heal, Buff, Debuff). 
		It is a tree, and element is a SkillNode. 
		SkillTree allocate new SkillNode. So This must free SkillNodes when destruction. 
================================================== */
class HealSkillTree : public SkillTree{
 public:
 	typedef Skill::ID ID;
 	typedef Skill::Type Type;
 	typedef pair<int, SkillNode *> Node;
 	typedef map<int, SkillNode *> Tree;
	SkillTree ();
	~SkillTree ();
 private:
 	virtual void Init() = 0;
 	void InsertSkill(SkillNode *snode);
 	void Clear();
 	Tree tree_;
};