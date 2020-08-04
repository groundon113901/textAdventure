/*
 *  Text Adventure
 *  By James Cranston (s3609326) & Justin Gerussi (s3644927)
 *
 */
#include "headers/armour.h"

Armour::Armour(int id, string name, string desc, int value, WearPosition position, int defense)
:Item(id, move(name), move(desc), value, position)
{
    this->defense = defense;
}

int Armour::getDefense(){
    return defense;
}