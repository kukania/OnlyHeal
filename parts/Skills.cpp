#include "Skill.h"
#include "../Character.h"
#define SECOND  1000
#define MINUTE  1000000

class HealSkill : Skill{
private:
    float   effi;                       // efficienty of skill
    int     time;
public:
    HealSkill(int _ID, string _name, Skill *_parent, int _cooltime, bool _isM, float _effi, int _time)
    :Skill(_ID, _name, _parent, _cooltime, 0){
        setEffi(_effi);
        setMulti(_isM);
    }

    void setEffi(float _effi){
        effi = _effi;
    }
    float getEffi(){
        return effi;
    }
    virtual int activate(Character *t, Character c){
        int power = c.getDamage();      // Caster's level
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