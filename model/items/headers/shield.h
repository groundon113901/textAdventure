/*
 *  Text Adventure
 *  By James Cranston (s3609326) & Justin Gerussi (s3644927)
 *
 */
#ifndef TEXTADVENTURE_CPP_SHIELD_H
#define TEXTADVENTURE_CPP_SHIELD_H

#include <string>
#include "item.h"

using namespace std;

class Shield : public Item {
private:
    int defense;

public:
    Shield(int id, string name, string description, int value, int defense);
};


#endif
