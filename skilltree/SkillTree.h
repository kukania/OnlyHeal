/*
FileName: 	SkillTree.h
Revision: 	2016/09/07 by PorcaM
Modified: 	2016/09/09 by PorcaM
*/

#include "SkillNode.h"
#include <map>

typedef pair<int, SkillNode*> 			NodeType;
typedef map<int, SkillNode*>			TreeType;
typedef map<int, SkillNode*>::iterator	TreeIt;

class SkillTree{
private:
	TreeType _tree; 	/* Key is Skill's ID. Value is Node for essential information */
public:
	SkillTree ();
	~SkillTree ();
	void 		insertSkill (SkillNode*);
	SkillNode* 	findSkill (SkillID);
	void 		removeSkill (SkillID);
	void 		initHealSkillTree ();
	int 		learnSkill (SkillID);
};