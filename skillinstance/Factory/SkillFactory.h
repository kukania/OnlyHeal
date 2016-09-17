/*
FileName: 	SkillFactory.h
Revision: 	2016/08/23 by PorcaM
Modified:	2016/09/05 by PorcaM
*/

#pragma once
#include "parts\Skill.h"
#include "cocos2d.h"
#include <vector>
USING_NS_CC;

typedef vector<Skill*> SV;
typedef vector<Skill*>::iterator SVI;

class SkillFactory{
protected:
	SV Akashic;
public:
	SkillFactory();
	~SkillFactory();
	SVI 	getBegin ();
	SVI 	getEnd ();
	void 	clearFactory ();
	void 	pushSkill (Skill*);
	virtual void	initAllSkills() = 0;
	virtual Skill*	createSkill();
	virtual Skill*	getSkill(int);
	virtual Skill** getSkillsList(int);
};