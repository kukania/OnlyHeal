#include "SkillTree.h"

// debug function
bool isRange(char *an, int a, int max, int min) {
	if (a < min) {
		printf("[%s: %d] is little than MIN: %d\n", an, a, min);
		return false;
	}
	if (a > max) {
		printf("[%s: %d] is larger than MAX: %d\n", an, a, max);
		return false;
	}
	return true;
}

Node::Node(SkillID _ID) {
	Node(_ID, 0, false);
	return;
}
Node::Node(SkillID _ID, SkillID _prec) {
	setID(_ID);
	setPrec(_prec);
	return;
}
Node::Node(SkillID _ID, SkillID _prec, bool _acquire) {
	setID(_ID);
	setPrec(_prec);
	setAcquire(_acquire);
	return;
}
SkillID	Node::getID() {
	return ID;
}
SkillID Node::getPrec() {
	return prec;
}
bool Node::getAcquire() {
	return acquire;
}
void Node::setID(SkillID _ID) {
	if (isRange("ID", _ID, 9999, 1)) return;
	ID = _ID;
	return;
}
void Node::setPrec(SkillID _prec) {
	if (isRange("PREC", _prec, 9999, 0))
		_prec = 0;
	prec = _prec;
	return;
}
void Node::setAcquire(bool _acquire) {
	acquire = _acquire;
	return;
}

/*SkillTree*/
SkillTree::SkillTree() {
	setPoint(0);
	skills.clear();
	return;
}
int SkillTree::getPoint() {
	return point;
}
void SkillTree::setPoint(int _point) {
	if (isRange("point", _point, 9999, 0))
		_point = 0;
	point = _point;
	return;
}
void SkillTree::addPoint(int _value) {
	setPoint(point + _value);
	return;
}
void SkillTree::addSkill(Node _node) {
	skills.insert(s_pair(_node.getID(), _node));
}
int SkillTree::acquire(SkillID _ID) {
	/*find skill*/
	if (skills.find(_ID) == skills.end()) 
		return 0;
	/*acquired precede condition*/
	bool prec = true;
	if(skills.find(_ID)->second.getPrec())	// if need precede acquirement
		prec = skills.find(skills.find(_ID)->second.getPrec())->second.getAcquire();
	/*enough point condition*/
	bool ep = (point >= LEARN_COST);
	if (prec && ep) {
		skills.find(_ID)->second.setAcquire(true);
		addPoint(-LEARN_COST);
	}
	return 0;
}