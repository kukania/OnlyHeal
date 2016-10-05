/* ==================================================
FileName: 	SkillNode.cpp
Revision: 	2016/09/07 by PorcaM
Modified: 	2016/10/04 by PorcaM
================================================== */

#include "skilltree/SkillNode.h"

#include <cstdio>

/* ==================================================
	Getter, Setter
================================================== */
void SkillNode::set_id(Skill::ID id){
	if (id < 0) {
		assert(false);
	}
	id_ = id;
	return;
}
void SkillNode::set_prec_id(Skill::ID prec_id){
	if (prec_id < 0) {
		assert(false);
	}
	prec_id_ = prec_id;
	return;
}
void SkillNode::set_learn(bool learn){
	learn_ = learn;
	return;
}
auto SkillNode::get_col()->Index{
	return col_;
}
void SkillNode::set_col(Index col){
	if (col < 0) {
		assert(false);
	}
	col_ = col;
	return;
}
auto SkillNode::get_row()->Index{
	return row_;
}
void SkillNode::set_row(Index row){
	if (row < 0) {
		assert(false);
	}
	row_ = row;
	return;
}
void SkillNode::set_col_row(Index col, Index row){
	set_col(col);
	set_row(row);
	return;
}
/* ==================================================
	Public
================================================== */
SkillNode::SkillNode(Skill::ID id){
	SkillNode(id, 0, false);
}
SkillNode::SkillNode(Skill::ID id, Skill::ID prec_id, bool learn) {
	set_id(id);
	set_prec_id(prec_id);
	set_learn(learn);
	set_col_row(0, 0);
}

Skill::ID SkillNode::getID() {
	return id_;
}
void SkillNode::setID(Skill::ID id) {
	if (id < 0) {
		printf("Skill ID is not negative!\n");
	}
	id_ = id;
	return;
}
Skill::ID SkillNode::getPrev() {
	return prec_id_;
}
void SkillNode::setPrev(Skill::ID prev) {
	if (prev < 0) {
		printf("Skill ID is not negative!\n");
	}
	prec_id_ = prev;
	return;
}
bool SkillNode::getLearn() {
	return learn_;
}
void SkillNode::setLearn(bool learn) {
	learn_ = learn;
	return;
}