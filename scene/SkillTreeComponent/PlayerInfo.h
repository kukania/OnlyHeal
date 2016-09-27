/* ============================================================
FileName: 	PlayerInfo.h
Revision: 	2016/09/22 by PorcaM

This class has player's information used in skilltree. 
	1. Point
		This is cost for learning skill. 
		Updated when learn skill. (MUST BE UPDATED)
	2. SkillSet
		This is skills that used in RAID. 
		Updated when user want to. 
============================================================ */

#pragma once

#include "cocos2d.h"
#include "ui\CocosGUI.h"
USING_NS_CC;

#include "parts/Skill.h"
#include <vector>



class PlayerInfo{
private:
	typedef unsigned int 		point_t;
	typedef vector<Skill*> 	skillset_t;
	point_t		_point;
	skillset_t 	_skillslot;
public:
};