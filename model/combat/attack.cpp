/*
 *  Text Adventure
 *  By James Cranston (s3609326) & Justin Gerussi (s3644927)
 *
 */
#include "headers/attack.h"


Attack::Attack(int id, string name, string description, double hitRate, int dmg)
: GameObject(id, move(name), move(description))
{
    this->hitRate = hitRate;
    this->baseDamage = dmg;
}

double Attack::getHitRate() {
    return hitRate;
}

int Attack::getDamage() {
    return baseDamage;
}