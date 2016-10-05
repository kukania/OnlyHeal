/* ============================================================
FileName: 	SkillInfo.h
Revision: 	2016/09/27 by PorcaM
Modified: 	2016/10/05 by PorcaM
============================================================ */

#include "scene/SkillTreeComponent/SkillInfo.h"

SkillInfo::SkillInfo(){
	InitFactoryList();
	InitSkilltreeList();
}
SkillInfo::~SkillInfo(){
	ClearFactoryList();
	ClearSkilltreeList();
}
auto SkillInfo::get_factory_by_type(Type type)->SkillFactory*{
	auto list = factory_list_;
	if ((int)type > list.size()) {
		assert(false);
	}
	return list[(int)type];
}
auto SkillInfo::get_skilltree_by_type(Type type)->SkillTree*{
	auto list = skilltree_list_;
	if ((int)type > list.size()) {
		assert(false);
	}
	return list[(int)type];
}
auto SkillInfo::RetrieveSkillByID(ID id)->Skill*{
	auto sptr = (Skill*)NULL;
	auto list = factory_list_;
	for (int i = 0; i < list.size(); ++i) {
		auto factory = list[i];
		for (auto it = factory->getBegin(); it != factory->getEnd(); ++it) {
			auto target = *it;
			if (id == target->getID())
				sptr = target;
		}
	}
	return sptr;
}
void SkillInfo::InitFactoryList(){
	factory_list_.push_back(new HealSkillFactory());
	factory_list_.push_back(new BuffSkillFactory());
	factory_list_.push_back(new DebuffSkillFactory());
	for (int i = 0; i < factory_list_.size(); ++i) {
		factory_list_[i]->initAllSkills();
	}
	return;
}
void SkillInfo::ClearFactoryList(){
	auto wastebasket = factory_list_;
	for (auto it = wastebasket.begin(); it != wastebasket.end(); ++it) {
		delete *it;
	}
	wastebasket.clear();
	return;
}
void SkillInfo::InitSkilltreeList(){
	skilltree_list_.push_back(new HealSkillTree());
	skilltree_list_.push_back(new BuffSkillTree());
	skilltree_list_.push_back(new DebuffSkillTree());
	return;
}
void SkillInfo::ClearSkilltreeList(){
	auto wastebasket = skilltree_list_;
	for (auto it = wastebasket.begin(); it != wastebasket.end(); ++it) {
		delete *it;
	}
	return;
}