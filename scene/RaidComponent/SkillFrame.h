/*
FileName:	SkillFrame.h
Revision:	2016/08/30 by PorcaM
Modified:	2016/08/31 by PorcaM
*/

#include "cocos2d.h"
#include "parts\Skill.h"
USING_NS_CC;

class SkillFrame : public CCLayerColor {
private:
	Skill	*_skill;
	Sprite	*_bg;
	Label	*_label;
public:
	SkillFrame(Skill *);
	void initBG();
	void initLabel();
};