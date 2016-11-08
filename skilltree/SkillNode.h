/* ==================================================
FileName: 	SkillNode.h
Revision: 	2016/09/07 by PorcaM
Modified: 	2016/10/05 by PorcaM
================================================== */

#pragma once
#include "parts/Skill.h"

/* ==================================================
	ClassName: 	SkillNode
	Modified: 	2016/10/05 by PorcaM

	Context:
		Node used in SkillTree.
		No link to Skill instance or ptr.
================================================== */
class SkillNode{
 public:
 	typedef int Index;
	typedef Skill::ID ID;
 	SkillNode(ID id);
	SkillNode(ID id, ID prec_id, bool learn);
	auto get_id()->ID;
	void set_id(ID id);
	auto get_prec_id()->ID;
	void set_prec_id(ID prec_id);
	auto get_learn()->bool;
	void set_learn(bool learn);
	auto get_col()->Index;
	void set_col(Index val);
	auto get_row()->Index;
	void set_row(Index val);
	// Set col and row concurrently
	void set_col_row(Index col, Index row);
 private:
	ID id_;
	ID prec_id_;  // Precedence ID
	bool learn_;
	Index col_;
	Index row_;
};
