/*
 *  Text Adventure
 *  By James Cranston (s3609326) & Justin Gerussi (s3644927)
 *
 */
#include "headers/user.h"


User::User(int id, string name, size_t passwordHash, PlayerCharacter character) : character(character) {
    this->id = id;
    this->character = std::move(character);
    this->username = std::move(name);
    this->pwdHash = passwordHash;
}

string User::getUsername(){
    return username;
}

int User::getId() {
    return id;
}

PlayerCharacter* User::getCharacter() {
    return &character;
}

size_t User::getPasswordHash(){
    return this->pwdHash;
}

bool User::comparePwd(size_t password) {
    return password == this->pwdHash;
}

User::User() {
    this->id = -1;
    this->character = PlayerCharacter();
}
