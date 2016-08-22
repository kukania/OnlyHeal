#pragma once
#include <string>
#include "cocos2d.h"
using namespace std;

#define SECOND  1000
#define MINUTE  1000000
#define T_HEAL  0
#define T_BUFF  1
#define T_DEBU  2
#define T_TANK	3
#define T_MELEE 4
#define T_RANGE 5

typedef int SkillID;
typedef int Type;
typedef int time_ms;
typedef int time_s;

class Character;

class Skill :public cocos2d::Sprite{
protected:
	SkillID 	ID;
	string 		name;
	time_ms 	cooltime; 		// static time for cooldown
	time_ms 	cooldown; 		// dynamic value of cooldown
	time_s 		time; 			// persistant time of skill
	Type 		type; 			// type of skill
	bool 		multi;

public:	
	// ID, name, cooltime, time, type, multi
	Skill(SkillID, string, time_ms, time_ms, Type, bool);
	// getter
	SkillID 	getID();
	string		getName();
	time_ms 	getCooltime();
	time_ms 	getCooldown();
	time_ms 	getTime();
	Type		getType();
	bool 		getMulti();
	// setter
	void 		setID(SkillID);
	void		setName(string);
	void		setCooltime(time_ms);
	void 		setTime(time_s);
	void		setType(Type);
	void 		setMulti(bool);
	// main use
	virtual int activate(Character *, Character &) = 0;
	virtual int activate(Character *, Character &,int) = 0;
	void		setCooldown(); 	// when use skill
	bool		able();
	bool 		isMulti();
};