/* ============================================================
FileName: 	SkillSlot.h
Revision: 	2016/10/02 by PorcaM
Modified: 	2016/10/02 by PorcaM
============================================================ */

#include "scene/SkillTreeComponent/SkillSlot.h"

#include <string>

SkillSlot::SkillSlot(){
	list_.clear();
	list_.reserve(kMaxSlotNum);
}
SkillSlot::~SkillSlot(){
	list_.clear();
}
int SkillSlot::Size(){
	return list_.size();
}
auto SkillSlot::Begin(){
	return list_.begin();
}
auto SkillSlot::End(){
	return list_.end();
}
void SkillSlot::InsertSkill(Skill *skill){
	if (skill == NULL) {
		assert(false);
	}
	list_.push_back(skill);
	return;
}
void SkillSlot::RemoveSkill(int index){
	if (index < 0 || index > list_.size()) {
		assert(false);
	}
	auto it = list_.begin();
	while (index--) ++it;
	list_.erase(it);
	return;
}
void SkillSlot::RemoveSkill(SkillVec::iterator it){
	list_.erase(it);
	return;
}
auto SkillSlot::FindSkillWithIndex(int index)->SkillVec::iterator{
	if (index < 0 || index > list_.size()) {
		assert(false);
	}
	auto it = list_.begin();
	while (index--) ++it;
	return it;
}
auto SkillSlot::FindSkillWithSkill(Skill *skill){
	auto it = list_.begin();
	for (; it != list_.end(); ++it) {
		if ((*it)->getID() == skill->getID()) break;
	}
	return it;
}
void SkillSlot::Assign(SkillVec sv) {
	list_ = sv;
	return;
}
auto SkillSlot::get_list()->SkillVec {
	return list_;
}