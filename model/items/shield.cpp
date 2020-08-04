/*
 *  Text Adventure
 *  By James Cranston (s3609326) & Justin Gerussi (s3644927)
 *
 */
#include "headers/shield.h"


Shield::Shield(int id, string name, string desc, int value, int defense)
: Item(id, move(name), move(desc), value, SHIELD){
    this->defense = defense;
}