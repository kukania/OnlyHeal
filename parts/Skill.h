#pragma once
#include <string>
#include "cocos2d.h"
using namespace std;

#define SECOND  1000
#define MINUTE  1000000

typedef int SkillID;
typedef int Type;
typedef int time_ms;
typedef int time_s;

enum SkillType {
	heal, buff, debuff,
	tank, melee_atk, range_atk,
	unknown_skill
};

class Character;

class Skill{
protected:
	SkillID 	_ID;
	string 		_name;
	time_ms 	_cooltime; 		// static time for cooldown 		
	time_s 		_time; 			// persistant time of skill
	SkillType 	_type; 			// type of skill
	bool 		_multi;

public:	
	// ID, name, cooltime, time, type, multi
	Skill(SkillID, string, time_ms, time_s, SkillType, bool);
	// getter
	time_ms 	_cooldown;
	SkillID 	getID();
	string		getName();
	time_ms 	getCooltime();
	time_ms 	getCooldown();
	time_s 		getTime();
	SkillType	getType();
	bool 		getMulti();
	// setter
	void 		setID(SkillID);
	void		setName(string);
	void		setCooltime(time_ms);
	void 		setTime(time_s);
	void		setType(SkillType);
	void 		setMulti(bool);
	// main use
	virtual int activate(Character **, Character &) = 0;
	virtual int activate(Character **, Character &, int) = 0;
	void		setCooldown();
	bool		able();
	bool 		isMulti();
	void		printInfo();
};