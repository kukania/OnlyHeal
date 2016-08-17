#pragma once
#include "../parts/Skill.h"

class Node {
private:
	int		ID;
	bool	acquire;
public:
	Node();
	Node(int);
	Node(int, bool);
	int		getID();
	bool	getAcquire();
	void	setID(int);
	void	setAcquire(bool);
};

class SkillTree {
private:
	int		point;
public:

};