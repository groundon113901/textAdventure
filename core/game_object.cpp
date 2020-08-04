/*
 *  Text Adventure
 *  By James Cranston (s3609326) & Justin Gerussi (s3644927)
 *
 */
#include "headers/game_object.h"

GameObject::GameObject(int id, string name, string desc){
    this->id = id;
    this->name = move(name);
    this->description = move(desc);
}

GameObject::GameObject() {
    this->id = -1;
    this->name = "";
    this->description = "";
}

int GameObject::getId(){
    return id;
}

string GameObject::getName(){
    return name;
}

string GameObject::getDescription() {
    return description;
}

