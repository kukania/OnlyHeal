#pragma once
#include <string>
using namespace std;

#define SECOND  1000
#define MINUTE  1000000
#define T_HEAL  0
#define T_BUFF  1
#define T_DEBU  2

typedef int SkillID
typedef int Type;
typedef int Millisec

class Character;

class Skill {
private:
	int 		ID;
	string 		name;
	int 		parent; 		// ID of parent skill
	Millisec 	cooltime; 		// static time for cooldown
	Millisec 	cooldown; 		// dynamic value of cooldown
	Millisec 	time; 			// persistant time of skill
	Type 		type; 			// type of skill
	bool 		multi;

public:	
	// ID, name, parent, cooltime, time, type, multi
	Skill(SkillID, string, SkillID, Millisec, Millisec, Type, bool);
	// getter
	SkillID 	getID();
	string		getName();
	SkillID		getParent();
	Millisec 	getCooltime();
	Millisec 	getCooldown();
	Millisec 	getTime();
	Type		getType();
	bool 		getMulti();
	// setter
	void 		setID(SkillID);
	void		setName(string);
	void		setParent(SkillID);
	void		setCooltime(Millisec);
	void 		setTime(Millisec);
	void		setType(Type);
	void 		setMulti(bool);
	// main use
	virtual int activate(Character *, Character) = 0;
	void		setCooldown(); 	// when use skill
	bool		able();
	bool 		isMulti();
};