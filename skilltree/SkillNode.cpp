/* ==================================================
FileName: 	SkillNode.cpp
Revision: 	2016/09/07 by PorcaM
Modified: 	2016/10/05 by PorcaM
================================================== */

#include "skilltree/SkillNode.h"

#include <cstdio>

/* ==================================================
	Getter, Setter
================================================== */
auto SkillNode::get_id()->ID{
	return id_;
}
void SkillNode::set_id(ID id){
	if (id < 0) {
		assert(false);
	}
	id_ = id;
	return;
}
auto SkillNode::get_prec_id()->ID{
	return prec_id_;
}
void SkillNode::set_prec_id(ID prec_id){
	if (prec_id < 0) {
		assert(false);
	}
	prec_id_ = prec_id;
	return;
}
auto SkillNode::get_learn()->bool{
	return learn_;
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
SkillNode::SkillNode(ID id){
	SkillNode(id, 0, false);
}
SkillNode::SkillNode(ID id, ID prec_id, bool learn) {
	set_id(id);
	set_prec_id(prec_id);
	set_learn(learn);
	set_col_row(0, 0);
}