/*
FileName:	SkillFrame.h
Revision:	2016/08/30 by PorcaM
Modified:	2016/08/31 by PorcaM
*/

#include "cocos2d.h"
#include "ui\CocosGUI.h"
#include "parts\Skill.h"
USING_NS_CC;

class SkillFrame : public CCNode {
private:
	Skill		*_skill;
	ui::Button	*_button;
	Label		*_label;
public:
	SkillFrame(Skill *);
	void initBG();
	void initLabel();
};