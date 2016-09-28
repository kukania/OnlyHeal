/* ============================================================
FileName: 	SkillInfo.h
Revision: 	2016/09/27 by PorcaM
============================================================ */

#include "scene\SkillTreeComponent\SkillInfo.h"

SkillInfo::SkillInfo(){
	factory_arr_ = new SkillFactory*[3];
	factory_arr_[0] = new HealSkillFactory();
	factory_arr_[1] = new BuffSkillFactory();
	factory_arr_[2] = new DebuffSkillFactory();
	for (int i = 0; i < 3; ++i) {
		factory_arr_[i]->initAllSkills();
	}
	skilltree_arr_ = new SkillTree *[3];
	for (int i = 0; i < 3; ++i) {
		skilltree_arr_[i] = new SkillTree();
		skilltree_arr_[i]->InitWithType(static_cast<Skill::Type>(i));
	}
}

SkillInfo::~SkillInfo(){
	for (int i = 0; i < 3; i++){
		delete factory_arr_[i];
		delete skilltree_arr_[i];
	}
	delete[] factory_arr_;
	delete[] skilltree_arr_;
}

SkillFactory *SkillInfo::get_factory_by_type(Skill::Type type){
	if (type < 3) {
		return factory_arr_[type];
	} else {
		assert(false);
	}
	return NULL;
}

SkillTree *SkillInfo::get_skilltree_by_type(Skill::Type type){
	if (type < 3) {
		return skilltree_arr_[type];
	}
	else {
		assert(false);
	}
	return NULL;
}