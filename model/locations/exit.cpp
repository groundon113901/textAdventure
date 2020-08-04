/*
 *  Text Adventure
 *  By James Cranston (s3609326) & Justin Gerussi (s3644927)
 *
 */
#include "headers/exit.h"

Exit::Exit() {
    this->fromRoom = -1;
    this->toRoom = -1;
    this->roomIsOpen = false;
}

Exit::Exit(int fromRoom, int toRoom, Directions::Direction direction, bool roomIsOpen){
    this->direction = direction;
    this->fromRoom = fromRoom;
    this->roomIsOpen = roomIsOpen;
    this->toRoom = toRoom;
}

int Exit::getToRoom() {
    return toRoom;
}

bool Exit::getRoomIsOpen() {
    return roomIsOpen;
}

int Exit::getFromRoom(){
    return fromRoom;
}

void Exit::setRoomIsOpen(bool status) {
    this->roomIsOpen = status;
}

void Exit::setDirection(Directions::Direction directionSelected) {
    direction = directionSelected;
}

Directions::Direction Exit::getDirection() {
    return direction;
}

string Exit::getDirectionToString(){
    switch (direction){
        case Directions::NORTH:
            return "North";
        case Directions::SOUTH:
            return "South";
        case Directions::EAST:
            return "East";
        case Directions::WEST:
            return "West";
        default:
            return "Invalid";
    }
}




