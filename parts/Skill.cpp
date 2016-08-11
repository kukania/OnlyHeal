#include "Skill.h"
Skill::Skill(string _name, Skill *_parent, float _cooltime, int _type) {
	setName(_name);
	setParent(_parent);
	setCooltime(_cooltime);
	setType(_type);
}

void Skill::setName(string _name) {
	name = _name;
}
void Skill::setParent(Skill *_parent) {
	parent = _parent;
}
void Skill::setCooltime(float _cooltime) {
	if (_cooltime < 0)
		_cooltime = 0;
	cooltime = _cooltime;
}
void Skill::setType(int _type) {
	type = _type;
}
string Skill::getName() {
	return name;
}
Skill *Skill::getParent() {
	return parent;
}
float Skill::getCooltime() {
	return cooltime;
}
int Skill::getType() {
	return type;
}