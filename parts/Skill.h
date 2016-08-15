#pragma once
#include <string>
using namespace std;

#define SECOND  1000
#define MINUTE  1000000
#define T_HEAL  0
#define T_BUFF  1
#define T_DEBU  2

typedef int SkillID;
typedef int Type;
typedef int time_ms;
typedef int time_s;

class Character;

class Skill {
protected:
	int 		ID;
	string 		name;
	int 		parent; 		// ID of parent skill
	time_ms 	cooltime; 		// static time for cooldown
	time_ms 	cooldown; 		// dynamic value of cooldown
	time_s 		time; 			// persistant time of skill
	Type 		type; 			// type of skill
	bool 		multi;

public:	
	// ID, name, parent, cooltime, time, type, multi
	Skill(SkillID, string, SkillID, time_ms, time_ms, Type, bool);
	// getter
	SkillID 	getID();
	string		getName();
	SkillID		getParent();
	time_ms 	getCooltime();
	time_ms 	getCooldown();
	time_ms 	getTime();
	Type		getType();
	bool 		getMulti();
	// setter
	void 		setID(SkillID);
	void		setName(string);
	void		setParent(SkillID);
	void		setCooltime(time_ms);
	void 		setTime(time_ms);
	void		setType(Type);
	void 		setMulti(bool);
	// main use
	virtual int activate(Character *, Character) = 0;
	void		setCooldown(); 	// when use skill
	bool		able();
	bool 		isMulti();
};