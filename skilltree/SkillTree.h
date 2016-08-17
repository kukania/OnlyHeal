#pragma once
#include "../parts/Skill.h"
#include <vector>
#include <map>

#define LEARN_COST 5

class Node;

typedef map<SkillID, Node> s_map;
typedef pair<SkillID, Node> s_pair;

class Node {
private:
	SkillID		ID;
	SkillID		prec;
	bool		acquire;
public:
	/*Constructor*/
	Node(SkillID);
	Node(SkillID, SkillID);
	Node(SkillID, SkillID, bool);
	/*getter*/
	SkillID		getID();
	SkillID		getPrec();
	bool		getAcquire();
	/*setter*/
	void		setID(SkillID);
	void		setPrec(SkillID);
	void		setAcquire(bool);
};

class SkillTree {
private:
	int		point;
	s_map	skills;
public:
	/*Constructor*/
	SkillTree();
	/*getter*/
	int		getPoint();
	/*setter*/
	void	setPoint(int);
	/*main use*/
	void	addPoint(int);
	void	addSkill(Node);
	int		acquire(SkillID);
};