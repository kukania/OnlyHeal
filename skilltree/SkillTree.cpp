#include "SkillTree.h"
#include "../skillinstance/HealSkill.h"
#include "../myUtility.h"

sNode::sNode(SkillID _ID)
	:sNode(_ID, 0, false) {
	return;
}
sNode::sNode(SkillID _ID, SkillID _prec)
	:sNode(_ID, _prec, false) {
	return;
}
sNode::sNode(SkillID _ID, SkillID _prec, bool _acquire) {
	setID(_ID);
	setPrec(_prec);
	setAcquire(_acquire);
	return;
}
SkillID sNode::getID() {
	return ID;
}
SkillID sNode::getPrec() {
	return prec;
}
bool sNode::getAcquire() {
	return acquire;
}
void sNode::setID(SkillID _ID) {
	if (!isRange("ID", _ID, 9999, 1)) return;
	ID = _ID;
	return;
}
void sNode::setPrec(SkillID _prec) {
	if (!isRange("PREC", _prec, 9999, 0))
		_prec = 0;
	prec = _prec;
	return;
}
void sNode::setAcquire(bool _acquire) {
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
	if (!isRange("point", _point, 9999, 0))
		_point = 0;
	point = _point;
	return;
}
void SkillTree::addPoint(int _value) {
	setPoint(point + _value);
	return;
}
void SkillTree::addSkill(sNode _node) {
	printf("ID: %d, prec: %d\n", _node.getID(), _node.getPrec());
	skills.insert(s_pair(_node.getID(), _node));
}
int SkillTree::acquire(SkillID _ID) {
	/*find skill*/
	if (skills.find(_ID) == skills.end())
		return -1;
	/*acquired precede condition*/
	bool prec = true;
	if (skills.find(_ID)->second.getPrec())	// if need precede acquirement
		prec = skills.find(skills.find(_ID)->second.getPrec())->second.getAcquire();
	/*enough point condition*/
	bool ep = (point >= LEARN_COST);
	if (prec && ep) {
		skills.find(_ID)->second.setAcquire(true);
		addPoint(-LEARN_COST);
	}
	return 0;
}

void initHealSkillTree(SkillTree *hst) {
	hst->addSkill(sNode(1, 0));
	hst->addSkill(sNode(8, 1));
	hst->addSkill(sNode(15, 1));
	for (int i = 1; i < 7; i++) {
		hst->addSkill(sNode(i + 1, i));
		hst->addSkill(sNode(i + 8, i + 7));
		hst->addSkill(sNode(i + 15, i + 14));
	}
	return;
}