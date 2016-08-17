#pragma once
#include "../parts/Skill.h"

class Node {
private:
	int		ID;
	bool	unlock;
public:
	Node();
	Node(int);
	Node(int, bool);
};

class SkillTree {
private:
	int		point;
	Skill	*leaf[30];
public:

};