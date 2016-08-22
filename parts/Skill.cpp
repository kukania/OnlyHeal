#include "Skill.h"
#include "../myUtility.h"

Skill::Skill(SkillID _ID, string _name, time_ms _cooltime, time_s _time, Type _type, bool _multi) {
	setID(_ID);
	setName(_name);
	setCooltime(_cooltime);
	setTime(_time);
	setType(_type);
	setMulti(_multi);
	cooldown = 0;
}
// getter
SkillID Skill::getID(){
	return ID;
}
string Skill::getName() {
	return name;
}
time_ms Skill::getCooltime() {
	return cooltime;
}
time_ms Skill::getCooldown() {
	return cooldown;
}
time_s Skill::getTime(){
	return time;
}
Type Skill::getType() {
	return type;
}
bool Skill::getMulti(){
	return multi;
}
// setter
void Skill::setID(SkillID _ID){
	if (!isRange("ID", _ID, 9999, 1)) return;
	ID = _ID;
	return;
}
void Skill::setName(string _name) {
	name = _name;
	return;
}
void Skill::setCooltime(time_ms _cooltime) {
	if (!isRange("Cooltime", _cooltime, 999*MINUTE, 0))
		_cooltime = 0;
	cooltime = _cooltime;
	return;
}
void Skill::setTime(time_s _time){
	if (!isRange("Time", _time, 999*MINUTE, 0))
		_time = 0;
	time = _time;
	return;
}
void Skill::setType(Type _type) {
	if (!isRange("Type", _type, 999, 0));
	type = _type;
	return;
}
void Skill::setMulti(bool _multi){
	multi = _multi;
	return;
}
// main use
void Skill::setCooldown() {
	cooldown = cooltime;
	return;
}
bool Skill::able() {
	return (!cooldown);
}
bool Skill::isMulti(){
	return multi;
}