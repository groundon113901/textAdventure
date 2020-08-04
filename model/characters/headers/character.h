/*
 *  Text Adventure
 *  By James Cranston (s3609326) & Justin Gerussi (s3644927)
 *
 */
#ifndef TEXT_ADVENTURE_CPP_CHARACTER_H
#define TEXT_ADVENTURE_CPP_CHARACTER_H

#include <string>
#include <vector>
#include "../../combat/headers/attack.h"
#include "../../combat/headers/spell.h"

using namespace std;

class Character {
protected:
    int id, hp, maxHP, mana, maxMana;
    string name;
    vector<Attack> attacks;
    vector<Spell> spells;

public:
    Character();
    Character(int id, int hp, int mana);

    int getHp();

    void setHp(int hp);

    int getMana();

    void setMana(int mana);

    int getId();

    int getMaxHp();

    int getMaxMana();

    virtual void toString();
    //void attack(Attack attack, Character character);
    //void cast(Spell spell, Character character);
};
#endif
