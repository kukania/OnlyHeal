#pragma once
#include <string>
using namespace std;

class Character;

class Skill {
public:
	string	name;
	Skill	*parent;
	float	cooltime;
	int		type;

	Skill(string, Skill *, float, int);
	string	getName();
	Skill*	getParent();
	float	getCooltime();
	int		getType();
	void	setName(string);
	void	setParent(Skill*);
	void	setCooltime(float);
	void	setType(int);
	virtual int activate(Character *, Character)=0;
};