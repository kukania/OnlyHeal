/*
FileName: 	SkillNode.cpp
Revision: 	2016/09/07 by PorcaM
Modified: 	2016/09/09 by PorcaM
*/

#include "SkillNode.h"
#include <cstdio>

SkillNode::SkillNode (SkillID id, SkillID prev = 0, bool learn = false){
	setID(id);
	setPrev(prev);
	setLearn(learn);
}

SkillID 	SkillNode::getID(){
	return _id;
}
void 		SkillNode::setID(SkillID id){
	if (id < 0){
		printf ("Skill ID is not negative!\n");
	}
	_id = id;
}
SkillID 	SkillNode::getPrev(){
	return _prev;
}
void 		SkillNode::setPrev(SkillID prev){
	if (prev < 0){
		printf ("Skill ID is not negative!\n");
	}
	_prev = prev;
}
bool 		SkillNode::getLearn(){
	return _learn;
}
void 		SkillNode::setLearn(bool learn){
	_learn = learn;
}