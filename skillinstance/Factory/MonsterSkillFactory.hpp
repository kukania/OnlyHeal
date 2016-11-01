/* ============================================================
FileName:   MonsterSkillFactory.hpp
Generated:  2016/11/01 by PorcaM
Modified: 	2016/11/01 by PorcaM
============================================================ */

#ifndef MONSERT_SKILL_FACTORY
#define MONSERT_SKILL_FACTORY

#include "parts/Skill.h"

class MonsterSkillFactory{
public:
    typedef Skill*      SkillPtr;
    typedef SKill::ID   ID;
    void Init();
    auto CreateSkill()->SkillPtr;
    auto CreateSkill(ID id)->SkillPtr;
}

#endif /* end of include guard: MONSERT_SKILL_FACTORY */
