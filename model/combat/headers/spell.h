/*
 *  Text Adventure
 *  By James Cranston (s3609326) & Justin Gerussi (s3644927)
 *
 */
#ifndef TEXT_ADVENTURE_CPP_SPELL_H
#define TEXT_ADVENTURE_CPP_SPELL_H

#include "attack.h"

class Spell : public Attack {
private:
    int manaCost;

public:
    Spell(int, string, string, double, int, int);
    int getManaCost();
};


#endif
