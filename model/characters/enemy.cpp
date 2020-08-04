/*
 *  Text Adventure
 *  By James Cranston (s3609326) & Justin Gerussi (s3644927)
 *
 */
#include <iostream>
#include "headers/enemy.h"




Enemy ::Enemy(int id, int hp, int mana, string name, int attack, int defence, double dodgeRate, double spawnRate, string description) : Character(id, hp, mana){
    this->name = std::move(name);
    this->attack = attack;
    this->defence = defence;
    this->spawnRate = spawnRate;
    this->description = std::move(description);
    this->dodgeRate = dodgeRate;
}

string Enemy::getDescription()  {
    return description;
}

double Enemy::getDodgeRate() {
    return dodgeRate;
}

double Enemy::getSpawnRate()  {
    return spawnRate;
}

int Enemy::getAttack() {
    return attack;
}

int Enemy::getDefence() {
    return defence;
}

string Enemy::enemyToString() {
    Character::toString();
    cout << "Name: " << name << endl;
    cout << "Attack: " << attack << endl;
    cout << "Defence: " << defence << endl;
    cout << "Spawn Rate: " << name << endl;
    cout << "Description: " << description << endl;
    cout << "Dodge Rate: " << dodgeRate << endl;

    return "";
}


