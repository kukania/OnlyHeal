/*
FileName: 	SkillNode.h
Revision: 	2016/09/07 by PorcaM
Modified: 	2016/09/27 by PorcaM
*/

#pragma once
#include "parts/Skill.h"

class SkillNode{
 public:
	SkillNode(SkillID, SkillID, bool);
	SkillID 	getID();
	void 		setID(SkillID);
	SkillID 	getPrev();
	void 		setPrev(SkillID);
	bool 		getLearn();
	void 		setLearn(bool);
	void set_col(int val);
	int get_col();
	void set_row(int val);
	int get_row();
	void set_col_n_row(int val_c, int val_r);
 private:
	SkillID _id;
	SkillID _prev;
	bool 	_learn;
	int 	col_, row_;
};