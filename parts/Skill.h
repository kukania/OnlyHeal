#pragma once
#include <string>
using namespace std;

class Character;

class Skill {
public:
	int 	ID;
	string	name;
	int		ID;
	Skill	*parent;
	int		cooltime;
	int		cooldown;
	int		type;
	bool	isMulti;

<<<<<<< HEAD
	Skill(int, string, Skill *, int, int);
	
=======
	Skill(int, string, Skill *, int, int); 	// name, parent, cooltime, type
	int 	getID();
>>>>>>> 68ff0a335458818d594cfc5a335174f9da84278d
	string	getName();
	Skill*	getParent();
	int		getCooltime();
	int		getCooldown();
	int		getType();
<<<<<<< HEAD

=======
	bool 	getMulti();

	void 	setID(int);
>>>>>>> 68ff0a335458818d594cfc5a335174f9da84278d
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