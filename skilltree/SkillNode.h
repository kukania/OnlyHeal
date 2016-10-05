/* ==================================================
FileName: 	SkillNode.h
Revision: 	2016/09/07 by PorcaM
Modified: 	2016/10/04 by PorcaM
================================================== */

#pragma once
#include "parts/Skill.h"

class SkillNode{
 public:
 	typedef int Index;
 	SkillNode(Skill::ID id);
	SkillNode(Skill::ID id, Skill::ID prec_id, bool learn);
	Skill::ID 	getID();
	void 		setID(Skill::ID);
	Skill::ID 	getPrev();
	void 		setPrev(Skill::ID);
	bool 		getLearn();
	void 		setLearn(bool);
	void set_id(Skill::ID id);
	void set_prec_id(Skill::ID prec_id);
	void set_learn(bool learn);
	auto get_col()->Index;
	void set_col(Index val);
	auto get_row()->Index;
	void set_row(Index val);
	void set_col_row(int val_c, int val_r);
 private:
	Skill::ID id_;
	Skill::ID prec_id_;  // Precedence ID
	bool learn_;
	Index col_;
	Index row_;
};