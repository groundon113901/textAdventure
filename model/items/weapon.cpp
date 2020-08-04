/*
 *  Text Adventure
 *  By James Cranston (s3609326) & Justin Gerussi (s3644927)
 *
 */
#include "headers/weapon.h"


Weapon::Weapon(int id, string name, string description, int value, int attack)
: Item(id, move(name), move(description), value, WEAPON) {
    this->attack = attack;
}