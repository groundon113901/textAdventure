/*
 *  Text Adventure
 *  By James Cranston (s3609326) & Justin Gerussi (s3644927)
 *
 */
#ifndef TEXT_ADVENTURE_CPP_ENEMY_H
#define TEXT_ADVENTURE_CPP_ENEMY_H

#include "character.h"

class Enemy : public Character{
private:
    string description;
    //Item dropItem;
    string name;
    double dodgeRate, spawnRate;
    int attack, defence;
public:
    Enemy(int id, int hp, int mana, string name, int attack, int defence, double dodgeRate, double spawnRate, string description);

    string getDescription();

    double getDodgeRate();

    double getSpawnRate();

    int getAttack();

    int getDefence();

    string enemyToString();
};


#endif
