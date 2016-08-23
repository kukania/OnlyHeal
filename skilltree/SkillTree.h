#pragma once
#include "../parts/Skill.h"
#include <vector>
#include <map>

#define LEARN_COST 	5

class sNode;

typedef map<SkillID, sNode> 	s_map;
typedef pair<SkillID, sNode> 	s_pair;

class sNode {
private:
	SkillID		ID;
	SkillID		prec;
	bool		acquire;
public:
	sNode(SkillID);
	sNode(SkillID, SkillID);
	sNode(SkillID, SkillID, bool);
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
	void	addSkill(sNode);
	int		acquire(SkillID);
};

void initHealSkillTree(SkillTree *);