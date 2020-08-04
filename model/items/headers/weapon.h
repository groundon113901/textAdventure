/*
 *  Text Adventure
 *  By James Cranston (s3609326) & Justin Gerussi (s3644927)
 *
 */
#ifndef TEXTADVENTURE_CPP_WEAPON_H
#define TEXTADVENTURE_CPP_WEAPON_H

#include "item.h"

class Weapon : public Item {
private:
    int attack;

public:
    Weapon(int id, string name, string description, int value, int attack);

};


#endif
