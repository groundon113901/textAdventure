/*
 *  Text Adventure
 *  By James Cranston (s3609326) & Justin Gerussi (s3644927)
 *
 */
#ifndef TEXTADVENTURE_CPP_ATTACK_H
#define TEXTADVENTURE_CPP_ATTACK_H

#include <string>
#include "../../../core/headers/game_object.h"

class Attack : public GameObject{
private:
    double hitRate;
    int baseDamage;


public:
    Attack(int id, string name, string description, double hitRate, int baseDamage);
    double getHitRate();
    int getDamage();
};


#endif
