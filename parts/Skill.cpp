#include "Skill.h"
#include <cstdio>
using namespace std;

Skill::Skill(int _ID, string _name, int _parent, 
Millisec _cooltime, Millisec _time, Type _type, bool _multi) {
	setID(_ID);
	setName(_name);
	setParent(_parent);
	setCooltime(_cooltime);
	setTime(_time);
	setType(_type);
	setMulti(_multi);
	cooldown = 0;
}
// getter
int Skill::getID(){
	return ID;
}
string Skill::getName() {
	return name;
}
int Skill::getParent() {
	return parent;
}
Millisec Skill::getCooltime() {
	return cooltime;
}
Millisec Skill::getCooldown() {
	return cooldown;
}
Millisec Skill::getTime(){
	return time;
}
Type Skill::getType() {
	return type;
}
bool Skill::getMulti(){
	return isMulti;
}
// setter
void Skill::setID(int _ID){
	if (isRange("ID", _ID, 9999, 1)) return;
	ID = _ID;
	return;
}
void Skill::setName(string _name) {
	name = _name;
	return;
}
void Skill::setParent(int _parent) {
	if (isRange("Parent", _parent, 9999, 0)) return;
	parent = _parent;
	return;
}
void Skill::setCooltime(Millisec _cooltime) {
	if (isRange("Cooltime", _cooltime, 999*MINUTE, 0))
		_cooltime = 0;
	cooltime = _cooltime;
	return;
}
void Skill::setTime(Millisec _time){
	if (isRange("Time", _time, 999*MINUTE, 0))
		_time = 0;
	time = _time;
	return;
}
void Skill::setType(Type _type) {
	if (isRange("Type", _type, 999, 0));
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
// debug function
bool isRange(char *an, int a, int max, int min){
	if (a < min){
		printf ("[%s: %d] is little than MIN: %d\n", an, a, min);
		return false;
	}
	if (a > max){
		printf ("[%s: %d] is larger than MAX: %d\n", an, a, max);
		return false;
	}
	return true;
}