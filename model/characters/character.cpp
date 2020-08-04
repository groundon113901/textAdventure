/*
 *  Text Adventure
 *  By James Cranston (s3609326) & Justin Gerussi (s3644927)
 *
 */
#include <iostream>
#include "headers/character.h"

Character::Character(int id, int maxHP, int maxMana){
    this->id = id;
    this->maxHP = maxHP;
    this->hp = maxHP;
    this->mana = maxMana;
    this->maxMana = maxMana;
}

int Character::getHp() {
    return hp;
}

void Character::setHp(int amount) {
    Character::hp = hp - amount;
}

int Character::getMana() {
    return mana;
}

void Character::setMana(int amount) {
    Character::mana = mana - amount;
}

int Character::getId() {
    return id;
}

int Character::getMaxHp() {
    return maxHP;
}

int Character::getMaxMana() {
    return maxMana;
}

void Character::toString() {
    cout << "ID: " << id << endl;
    cout << "MaxHP: " << maxHP << endl;
    cout << "HP: " << hp << endl;
    cout << "MaxMana: " << maxMana << endl;
    cout << "Mana: " << mana << endl;
}

Character::Character() {

}

/*
void Character::attack(Attack attack, Character character){

}

void Character::cast(Spell spell, Character character){

}
*/
