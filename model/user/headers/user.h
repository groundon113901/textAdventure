/*
 *  Text Adventure
 *  By James Cranston (s3609326) & Justin Gerussi (s3644927)
 *
 */
#ifndef TEXTADVENTURE_CPP_USER_H
#define TEXTADVENTURE_CPP_USER_H

#include <string>
#include <boost/serialization/access.hpp>
#include "../../characters/headers/player_character.h"

class User {

private:
    int id;
    string username;
    size_t pwdHash;
    PlayerCharacter character;
public:
    User();
    User(int id, string name, size_t passwordHash, PlayerCharacter character);
    string getUsername();
    int getId();
    PlayerCharacter* getCharacter();
    size_t getPasswordHash();
    bool comparePwd(size_t password);

    friend boost::serialization::access;

    template<typename Archive>
    void serialize(Archive& archive, const unsigned version){
        archive & id & username & pwdHash & character;
    }
};


#endif
