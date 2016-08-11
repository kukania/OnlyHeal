#pragma once
#include <string>
using namespace std;

class Character;

class Skill {
public:
	string	name;
	Skill	*parent;
	int		cooltime;
	int		cooldown;
	int		type;
	bool	isMulti;

	Skill(string, Skill *, int, int);
	
	string	getName();
	Skill*	getParent();
	int		getCooltime();
	int		getCooldown();
	int		getType();

	void	setName(string);
	void	setParent(Skill*);
	void	setCooltime(int);
	void	setCooldown(int);
	void	setType(int);

	virtual int activate(Character *, Character) = 0;
	void	setCooldown();
	bool	able();
};