/* ============================================================
FileName: 	PlayerInfo.h
Revision: 	2016/09/27 by PorcaM
Modified: 	2016/10/02 by PorcaM
============================================================ */

#include "scene/SkillTreeComponent/PlayerInfo.h"

#include <string>

/* ============================================================
	Public Getter and Setter. 
============================================================ */
auto PlayerInfo::get_point()->int{
	return point_;
}
auto PlayerInfo::get_slot()->SkillSlot *{
	return slot_;
}
/* ============================================================
	Public
============================================================ */
PlayerInfo::PlayerInfo(){
	set_point(0);
	set_slot(new SkillSlot());
}
PlayerInfo::PlayerInfo(int point, SkillSlot *slot){
	set_point(point);
	set_slot(slot);
}
PlayerInfo::~PlayerInfo(){
	delete slot_;
}
void PlayerInfo::AddPoint(int value){
	set_point(point_ + value);
	return;
}
/* ============================================================
	Private
============================================================ */
void PlayerInfo::set_point(int point){
	if (point < 0) {
		point = 0;
	}
	point_ = point;
	return;
}
void PlayerInfo::set_slot(SkillSlot *slot){
	if (slot == NULL) {
		assert(false);
	}
	slot_ = slot;
	return;
}