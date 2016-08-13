#include "Skill.h"
#include "../Character.h"
#define SECOND  1000
#define MINUTE  1000000

class HealSkill : Skill{
private:
    float effi;                         // efficienty of skill
public:
    HealSkill(string _name, Skill *_parent, int _cooltime)
    :Skill(_name, _parent, _cooltime, 0){
        setEffi(_effi);
    }

    void setEffi(float _effi){
        effi = _effi;
    }
    float getEffi(){
        return effi;
    }
    virtual int activate(Character *t, Character c){
        int power = c.getDamage();      // Caster's level
        int amount = effi * power;
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

void initSkills(){
    HealSkill hs1 = HealSkill("기본힐링", NULL, 1*SECOND);
}