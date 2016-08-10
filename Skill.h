#pragma once
#include <string>
using namespace std;

class Character;

class Skill {
public:
	string	name;
	Skill	*parent;
	float	cooltime;
	Skill();
	Skill(string, Skill *, float);
	string	getName();
	Skill*	getParent();
	float	getCooltime();
	void	setName(string);
	void	setParent(Skill*);
	void	setCooltime(float);
	virtual int activate(Character *, Character);
};