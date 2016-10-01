/* ============================================================
FileName: 	PlayerInfo.h
Revision: 	2016/09/27 by PorcaM
Modified: 	2016/10/02 by PorcaM
============================================================ */

#include "scene/SkillTreeComponent/PlayerInfo.h"

#include <string>

/* ============================================================
	Getter and Setter. 
============================================================ */
get_point(){
	return point_;
}
auto PlayerInfo::get_slot(){
	return slot_;
}
/* ============================================================
	Public
============================================================ */
PlayerInfo::PlayerInfo(){
	set_skill_num(0);
	set_point(10);
}
PlayerInfo::~PlayerInfo(){

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