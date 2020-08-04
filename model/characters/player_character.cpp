/*
 *  Text Adventure
 *  By James Cranston (s3609326) & Justin Gerussi (s3644927)
 *
 */
#include "headers/player_character.h"

PlayerCharacter::PlayerCharacter() : Character() {

}

PlayerCharacter ::PlayerCharacter(int id, int hp, int mana, int gold, int intelligence, int wisdom,
                                  int constitution, int strength, int dexterity, int locationNo, int moves, Slots slots)
: Character(id, hp, mana) {
    this->gold = gold;
    this->dexterity = dexterity;
    this->intelligence = intelligence;
    this->wisdom = wisdom;
    this->strength = strength;
    this->constitution = constitution;
    this->locationNo = locationNo;
    this->moves = moves;
    this->moveLimit = moves;
    this->itemSlots = std::move(slots);
}

int PlayerCharacter::getGold() {
    return gold;
}

//Return false if player doesn't have enough gold
bool PlayerCharacter::alterGold(int amnt) {
    if(gold + amnt > 0){
        gold += amnt;
        return true;
    }

    return false;
}

int PlayerCharacter::getIntelligence()  {
    return intelligence;
}

int PlayerCharacter::getWisdom()  {
    return wisdom;
}

int PlayerCharacter::getStrength() {
    return strength;
}

int PlayerCharacter::getConstitution()  {
    return constitution;
}

int PlayerCharacter::getDexterity()  {
    return dexterity;
}

int PlayerCharacter::getLocationNo() {
    return locationNo;
}

void PlayerCharacter::setLocationNo(int locationNumber) {
    locationNo = locationNumber;
}

void PlayerCharacter::setIntelligence(int level) {
    intelligence = level;
}

void PlayerCharacter::setWisdom(int level) {
    wisdom = level;
}

void PlayerCharacter::setConstitution(int level) {
    constitution = level;
}

void PlayerCharacter::setDexterity(int level) {
    dexterity = level;
}

int PlayerCharacter::getMoveLimit(){
    return moveLimit;
}

int PlayerCharacter::getMoves(){
    return moves;
}

void PlayerCharacter::setMoves(int amnt){
    this->moves = amnt;
}

Slots PlayerCharacter::getItemSlots() {
    return itemSlots;
}

void PlayerCharacter::setSlots(Slots slots) {
    this->itemSlots = std::move(slots);
}

void PlayerCharacter::playerToString() {
    Character::toString();
    cout << "Dexerity: " << dexterity << endl;
    cout << "Intelligence: " << intelligence << endl;
    cout << "Wisdom: " << wisdom << endl;
    cout << "Strength: " << strength << endl;
    cout << "Constitution: " << constitution << endl;
    cout << "Location Number: " << locationNo << endl;
    cout << "Moves: " << moves << endl;
    cout << "Item Slots: ";
    itemSlots.toString();
}




