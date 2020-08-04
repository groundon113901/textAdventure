/*
 *  Text Adventure
 *  By James Cranston (s3609326) & Justin Gerussi (s3644927)
 *
 */
#include "headers/room.h"


Room::Room() : GameObject() {

}

Room::Room(int id, string name, string description, int areaId, int areaRoomId, vector<Item> items)
: GameObject(id, std::move(name), std::move(description)){
    this->areaId = areaId;
    this->areaRoomId = areaRoomId;
    this->items = std::move(items);
}

void Room::setItems(vector<Item> item){
    items = std::move(item);
}

void Room::setEnemies(vector<Enemy> enemy){
    enemies = std::move(enemy);
}

void Room::setRoomExits(map<Directions::Direction,Exit> adjacentRoom){
    adjacentRooms = std::move(adjacentRoom);
}

int Room::getAreaId(){
    return areaId;
}

int Room::getAreaRoomId(){
    return areaRoomId;
}

vector<Enemy> Room::getEnemies(){
    return enemies;
}

map<Directions::Direction,Exit> Room::getRoomExits(){
    return adjacentRooms;
}

map<int, Room> Room::getRooms(const map<int, Room>& gameRooms, int areaId) {
    map<int, Room> rooms;
    for(pair<int, Room> roomPair : gameRooms){
        if(roomPair.second.getAreaId() == areaId){
            rooms.insert(pair<int, Room>(roomPair.second.getId(), roomPair.second));
        }
    }
    return rooms;
}

vector<Item> Room::getItems(){
    return items;
}

void Room::addItem(Item item) {
    items.emplace_back(item);
}

void Room::removeItem(Item item) {
    auto pos = std::find(items.begin(), items.end(), item);
    items.erase(pos);
}


int Room::getItemCount() {
    return items.size();
}



