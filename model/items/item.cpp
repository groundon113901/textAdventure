/*
 *  Text Adventure
 *  By James Cranston (s3609326) & Justin Gerussi (s3644927)
 *
 */
#include "headers/item.h"


Item::Item(int id, string name, string description, int value, WearPosition position)
: GameObject(id, move(name), move(description)){
    this->value = value;
    this->wearPosition = position;
}

Item::Item() : GameObject(){
    //For null returns
}

Item::WearPosition Item::positionFromString(string& str) {
    if(str == "HEAD") {
        return HEAD;
    }else if(str == "ARMS") {
        return ARMS;
    }else if(str == "HANDS") {
        return HANDS;
    }else if(str == "TORSO") {
        return TORSO;
    }else if(str == "WRISTS") {
        return WRISTS;
    }else if(str == "LEGS") {
        return LEGS;
    }else if(str == "FEET") {
        return FEET;
    }else if(str == "WEAPON") {
        return WEAPON;
    }else {
        return SHIELD;
    }
}

string Item::wearPositionToString(Item::WearPosition pos) {
    switch(pos){
        case Item::HEAD:
            return "HEAD";
        case Item::TORSO:
            return "TORSO";
        case Item::ARMS:
            return "ARMS";
        case Item::WRISTS:
            return "WRISTS";
        case Item::HANDS:
            return "HANDS";
        case Item::SHIELD:
            return "SHIELD";
        case Item::WEAPON:
            return "WEAPON";
        case Item::LEGS:
            return "LEGS";
        case Item::FEET:
            return "FEET";
        default:
            return "INVALID";
    }
}

string Item::getDescription() {
    return description;
}

int Item::getValue() {
    return value;
}

Item::WearPosition Item::getWearPosition() {
    return wearPosition;
}

bool Item::operator==(const Item &i1) {
    return id == i1.id;
}
