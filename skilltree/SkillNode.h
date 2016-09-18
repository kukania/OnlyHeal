/*
FileName: 	SkillNode.h
Revision: 	2016/09/07 by PorcaM
Modified: 	2016/09/09 by PorcaM
*/

#pragma once
#include "parts/Skill.h"

class SkillNode{
private:
	SkillID _id;
	SkillID _prev;
	bool 	_learn;
public:
	SkillNode(SkillID, SkillID, bool);
	SkillID 	getID();
	void 		setID(SkillID);
	SkillID 	getPrev();
	void 		setPrev(SkillID);
	bool 		getLearn();
	void 		setLearn(bool);
};