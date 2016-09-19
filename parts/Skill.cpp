#include "Skill.h"
#include "../myUtility.h"
#include <cstdio>

Skill::Skill(SkillID ID, string name, time_ms cooltime, 
time_s time, SkillType type, bool multi) {
	setID(ID);
	setName(name);
	setCooltime(cooltime);
	setTime(time);
	setType(type);
	setMulti(multi);
	_cooldown = 0;
}
// getter
SkillID Skill::getID(){
	return _ID;
}
string Skill::getName() {
	return _name;
}
time_ms Skill::getCooltime() {
	return _cooltime;
}
time_ms Skill::getCooldown() {
	return _cooldown;
}
time_s Skill::getTime(){
	return _time;
}
SkillType Skill::getType() {
	return _type;
}
bool Skill::getMulti(){
	return _multi;
}
// setter
void Skill::setID(SkillID ID){
	if (isRange("ID", ID, 9999, 1) != 0) 
		return;
	_ID = ID;
	return;
}
void Skill::setName(string name) {
	_name = name;
	return;
}
void Skill::setCooltime(time_ms cooltime) {
	if (isRange("Cooltime", cooltime, 999*MINUTE, 0) != 0)
		cooltime = 0;
	_cooltime = cooltime;
	return;
}
void Skill::setTime(time_s time){
	if (isRange("Time", time, 999*MINUTE, 1) != 0)
		time = 1;
	_time = time;
	return;
}
void Skill::setType(SkillType type) {
	if (isRange("Type", type, 999, 0) != 0)
		type = unknown_skill;
	_type = type;
	return;
}
void Skill::setMulti(bool multi){
	_multi = multi;
	return;
}
// Activate when use skill
// setup cooldown as cooltime
void Skill::setCooldown() {
	_cooldown = _cooltime;
	return;
}
// Check cooldown is clear
bool Skill::able() {
	return _cooldown<=0?1:0;
}
bool Skill::isMulti(){
	return _multi;
}
void Skill::printInfo() {
	string typeName[7] = { "heal", "buff", "debuff", "tank", "melee", "range", "unknown" };
	printf("[%s] %d %s\n", typeName[getType()].c_str(), getID(), getName().c_str());
	return;
}