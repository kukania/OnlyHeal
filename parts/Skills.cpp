#include "Skill.h"
#include "../Character.h"

class HealSkill : Skill{
private:
    float   factor;                       // efficienty of skill
public:
    HealSkill(SkillID _ID, string _name, SkillID _parent, 
    time_ms _cooltime, time_s _time, bool _multi,
    float _factor)
    :Skill(_ID, _name, _parent, _cooltime, _time, 
    T_HEAL, _multi){
        factor = _factor;
    }
    virtual int activate(Character *t, Character c){
        int power = c.getStatus()->getDamage();      // Caster's level
        int amount = effi * power / time;
        setCooldown();
        for(int i = 0; i < time; i++){
            if (isMulit){
                for(int i = 2; i < 6; i++){
                    t[i].addHP(amount);
                }
            }
            else{
                t[0].addHP(amount);
            }
        }
    }
}

class BuffSkill : Skill{
private:
    int     max;
    int     stat;
    int     time;
public:
    BuffSkill(int _ID, string _name, int _parent, int _cooltime, 
    bool isM, int _max, int _stat, int _time)
    :Skill(_ID, _name, _parent, _cooltime, T_BUFF){

    }
}

void initSkills(){
    HealSkill hs[22];
    string  sPrefix = {"기본", "숙련", "완숙", "전문", "기적", "전설", "신화"};
    float   fCoeffi = {1.0f, 1.2f, 1.5f, 2.0f, 3.0f, 5.0f, 10.0f};
    for(int i = 0; i < 7; i++){
        hs[i] = HealSkill(i+1, sPrefix[i]+"힐링", i, fCoeffi, false, fCoeffi, 1);
    }
    for(int i = 0; i < 7; i++){
        hs[i+7] = HealSkill(i+8, sPrefix[i]+"광힐", i+7, fCoeffi*2, true, fCoeffi, 1);
    }
    for(int i = 0; i < 7; i++){
        hs[i+14] = HealSkill(i+15, sPrefix[i]+"힐샘", i+14, fCoeffi, false, fCoeffi*2, 10);
    }
    hs[21] = HealSkill(22, "힐샤워", 4, 5, true, 3, 5);
}