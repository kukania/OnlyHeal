/*
FileName: 	SkillNode.cpp
Revision: 	2016/09/07 by PorcaM
Modified: 	2016/09/09 by PorcaM
*/

#include "SkillNode.h"
#include <cstdio>

SkillNode::SkillNode(SkillID id, SkillID prev = 0, bool learn = false) {
	setID(id);
	setPrev(prev);
	setLearn(learn);
	col_ = row_ = 0;
}

SkillID SkillNode::getID() {
	return _id;
}
void SkillNode::setID(SkillID id) {
	if (id < 0) {
		printf("Skill ID is not negative!\n");
	}
	_id = id;
	return;
}
SkillID SkillNode::getPrev() {
	return _prev;
}
void SkillNode::setPrev(SkillID prev) {
	if (prev < 0) {
		printf("Skill ID is not negative!\n");
	}
	_prev = prev;
	return;
}
bool SkillNode::getLearn() {
	return _learn;
}
void SkillNode::setLearn(bool learn) {
	_learn = learn;
	return;
}

int SkillNode::get_col(){
	return col_;
}

void SkillNode::set_col(int val){
	assert(val>=0 && "col cannot be unsigned.");
	col_ = val;
	return;
}

int SkillNode::get_row(){
	return row_;
}

void SkillNode::set_row(int val){
	assert(val>=0 && "row cannot be unsigned.");
	row_ = val;
	return;
}

void SkillNode::set_col_n_row(int val_c, int val_r){
	set_col(val_c);
	set_row(val_r);
	return;
}