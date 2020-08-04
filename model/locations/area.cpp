/*
 *  Text Adventure
 *  By James Cranston (s3609326) & Justin Gerussi (s3644927)
 *
 */
#include "headers/area.h"

Area::Area() : GameObject() {

}

Area::Area(int id, string name, string description, map<int, Room> rooms) : GameObject(id, std::move(name), std::move(description)){
    this->rooms = std::move(rooms);
}

void Area::setRooms(map<int,Room> room){
    rooms = std::move(room);
}
void Area::insertRoom(int num, const Room& room){
   rooms.insert(pair<int, Room>(num, room));
}
map<int, Room> Area::getRooms(){
    return rooms;
}



