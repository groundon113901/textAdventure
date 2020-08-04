/*
 *  Text Adventure
 *  By James Cranston (s3609326) & Justin Gerussi (s3644927)
 *
 */
#ifndef TEXT_ADVENTURE_CPP_PLAYERCHARACTER_H
#define TEXT_ADVENTURE_CPP_PLAYERCHARACTER_H

#include <vector>
#include <iostream>
#include <boost/serialization/access.hpp>
#include "character.h"
#include "../../item_slots/headers/slots.h"


class PlayerCharacter : public Character{
private:
    int locationNo, intelligence, wisdom, strength, constitution, dexterity, moves, moveLimit, gold;
    Slots itemSlots;
public:
    PlayerCharacter();
    PlayerCharacter(int id, int hp, int mana, int gold, int intelligence, int wisdom,
                    int constitution, int strength, int dexterity, int locationNo, int moves, Slots slots);


    int getGold();
    bool alterGold(int);
    int getIntelligence();
    int getWisdom();
    int getStrength();
    int getConstitution();
    int getDexterity();
    int getLocationNo();
    void setLocationNo(int locationNo);
    void setIntelligence(int intelligence);
    void setWisdom(int wisdom);
    void setConstitution(int constitution);
    void setDexterity(int dexterity);
    int getMoveLimit();
    int getMoves();
    void setMoves(int);
    Slots getItemSlots();
    void setSlots(Slots slots);
    void playerToString();

    friend class boost::serialization::access;

    template<typename Archive>
    void serialize(Archive& archive, const unsigned version){
        archive & id & hp & mana & gold & intelligence & wisdom & constitution & strength & dexterity
        & locationNo & moves & itemSlots;
    }
};

#endif
