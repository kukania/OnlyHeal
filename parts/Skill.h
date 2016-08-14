#pragma once
#include <string>
using namespace std;

class Character;

class Skill {
public:
	int 	ID;
	string	name;
	Skill	*parent;
	int		cooltime;
	int		cooldown;
	int		type;
	bool	isMulti;

	Skill(int, string, Skill *, int, int); 	// name, parent, cooltime, type
	int 	getID();
	string	getName();
	Skill*	getParent();
	int		getCooltime();
	int		getCooldown();
	int		getType();
	bool 	getMulti();

	void 	setID(int);
	void	setName(string);
	void	setParent(Skill*);
	void	setCooltime(int);
	void	setCooldown(int);
	void	setType(int);
	void 	setMulti(bool);

	virtual int activate(Character *, Character) = 0;
	void	setCooldown();
	bool	able();
};