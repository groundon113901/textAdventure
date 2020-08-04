/*
 *  Text Adventure
 *  By James Cranston (s3609326) & Justin Gerussi (s3644927)
 *
 */
#include "headers/spell.h"

Spell::Spell(int id, string name, string description, double hitRate, int dmg, int manaCost)
: Attack(id, move(name), move(description), hitRate, dmg){
    this->manaCost = manaCost;
}

int Spell::getManaCost() {
    return manaCost;
}