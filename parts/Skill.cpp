#include "Skill.h"
Skill::Skill(string _name, Skill *_parent, int _cooltime, int _type) {
	setName(_name);
	setParent(_parent);
	setCooltime(_cooltime);
	setType(_type);
	cooldown = 0;
	isMulti = false;
}

void Skill::setName(string _name) {
	name = _name;
}
void Skill::setParent(Skill *_parent) {
	parent = _parent;
}
void Skill::setCooltime(int _cooltime) {
	if (_cooltime < 0)
		_cooltime = 0;
	cooltime = _cooltime;
}
void Skill::setCooldown(int _cooldown) {
	cooldown = _cooldown;
}
void Skill::setType(int _type) {
	type = _type;
}
void Skill::setMulti(bool _isMulti){
	isMulti = _isMulti;
}

string Skill::getName() {
	return name;
}
Skill *Skill::getParent() {
	return parent;
}
int Skill::getCooltime() {
	return cooltime;
}
int Skill::getCooldown() {
	return cooldown;
}
int Skill::getType() {
	return type;
}
bool Skill::getMulti(){
	return isMulti;
}

void Skill::setCooldown() {
	cooldown = cooltime;
	return;
}
bool Skill::able() {
	return (!cooldown);
}