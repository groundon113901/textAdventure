/*
 *  Text Adventure
 *  By James Cranston (s3609326) & Justin Gerussi (s3644927)
 *
 */
#ifndef TEXTADVENTURE_CPP_AMOUR_H
#define TEXTADVENTURE_CPP_AMOUR_H

#include "item.h"

class Armour : public Item{

private:
    int defense;

public:
    Armour(int id, string name, string desc, int value, WearPosition position, int defense);
    int getDefense();
};


#endif
