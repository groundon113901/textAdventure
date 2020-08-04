/*
 *  Text Adventure
 *  By James Cranston (s3609326) & Justin Gerussi (s3644927)
 *
 */
#include "headers/game_model.h"


GameModel::GameModel() {
    currentUser = User();
}

GameModel::GameModel(User user) {
    setCurrentUser(move(user));
}

void GameModel::isAscii(bool state) {
    isAsciiModel = state;
}

bool GameModel::isAscii() const {
    return isAsciiModel;
}

/* User */
void GameModel::setUsers(map<string, User> users) {
    this->users = users;
}

map<string, User> GameModel::getUsers() {
    mergeCurrentUser();
    return users;
}

void GameModel::mergeCurrentUser(){
    currentUser.getCharacter()->setLocationNo(currentRoom);
    auto it = users.find(currentUser.getUsername());
    if(it != users.end())
        it->second = currentUser;
}

void GameModel::setCurrentUser(User user) {
    currentUser = move(user);
    int location = currentUser.getCharacter()->getLocationNo();
    if(location == -1 && currentUser.getId() != -1){
        currentUser.getCharacter()->setLocationNo(4);
        location = 4;
    }
    currentRoom = location;
}

User* GameModel::getUserByUsername(string un) {
    auto it = users.find(un);
    if(it != users.end()){
        return &it->second;
    }else{
        return new User();
    }

}

User* GameModel::getCurrentUser() {
    return &currentUser;
}

PlayerCharacter* GameModel::getCharacter() {
    return currentUser.getCharacter();
}

void GameModel::updateMoveCount(int amnt) {
    int count = currentUser.getCharacter()->getMoves();
    int limit = currentUser.getCharacter()->getMoveLimit();
    if((count + amnt) > -1 && (count + amnt) <= limit ){
        currentUser.getCharacter()->setMoves(count + amnt);
    }
}


/* Area */
void GameModel::setAreas(map<int, Area> areas) {
    this->areas = move(areas);
}

map<int, Area> GameModel::getAreas(){
    return areas;
}

Area GameModel::getAreaById(int areaId){
    return areas.find(areaId)->second;
}

vector<Room> GameModel::getRoomsByArea(int areaId){
    vector<Room> result;
    int count = rooms.size();
    for(int i =0; i < count; i++){
        if(rooms[i].getAreaId() == areaId){
            result.emplace_back(rooms[i]);
        }
    }

    return result;
}

/* Room */
void GameModel::setRooms(map<int, Room> rooms) {
    this->rooms = move(rooms);
}

map<int, Room> GameModel::getRooms(){
    return rooms;
}

void GameModel::setCurrentRoom(int id) {
    currentRoom = id;
}

int GameModel::getCurrentRoomId() {
    return currentRoom;
}

Room GameModel::getRoomById(int roomId){
    return rooms.find(roomId)->second;
}

void GameModel::setRoomItems(int roomId, vector<Item> items){
    getRoomById(roomId).setItems(items);
}

vector<Item> GameModel::getRoomItems(int roomId){
    return getRoomById(roomId).getItems();
}

void GameModel::insertRoomItem(const int roomId, Item item) {
    rooms.at(roomId).addItem(std::move(item));
}


void GameModel::removeRoomItem(int roomId, Item item) {
    rooms.at(roomId).removeItem(item);
}

map<Directions::Direction, Exit> GameModel::getRoomExitsMap(int roomId){
    return getRoomById(roomId).getRoomExits();
}

map<Directions::Direction, Exit> GameModel::generateRoomExitsMap(int roomId){
    map<Directions::Direction, Exit> result;

    for(auto exit : exits){
        if(exit.second.getFromRoom() == roomId){
            result.insert(pair<Directions::Direction, Exit>(exit.second.getDirection(), exit.second));
        }
    }

    return result;
}

void GameModel::updateRoomExits(Exit exit){
    Room fromRoom = getRoomById(exit.getFromRoom());
    map<Directions::Direction, Exit> fromExits = fromRoom.getRoomExits();
    fromExits.at(exit.getDirection()) = exit;
    fromRoom.setRoomExits(fromExits);
    rooms.at(fromRoom.getId()) = fromRoom;
}


void GameModel::openOrCloseDoor(Exit exit, Actions::Action action){
    int from = exit.getFromRoom();
    int to = exit.getToRoom();
    Exit fromExit = getExit(from, to);
    Exit toExit = getExit(to, from);
    if (action == Actions::CLOSE){
        fromExit.setRoomIsOpen(false);
        toExit.setRoomIsOpen(false);
    } else if (action == Actions::OPEN){
        fromExit.setRoomIsOpen(true);
        toExit.setRoomIsOpen(true);
    }
    updateRoomExits(fromExit);
    if(toExit.getFromRoom() > 0){
        updateRoomExits(toExit);
    }

}
/* Exit */
map<pair<int,int>, Exit> GameModel::getExits(){
    return exits;
}

void GameModel::setExits(map<pair<int, int>, Exit> exits) {
    this->exits  = move(exits);
}

Exit GameModel::getExit(int fromId, int toId){
    return exits.find(pair<int, int>(fromId, toId))->second;
}


/* Item */
map<int, Item> GameModel::getItems() {
    return items;
}

void GameModel::setItems(map<int, Item> items) {
    this->items = move(items);
}

Item GameModel::getItemById(int itemId) {
    return items.find(itemId)->second;
}


void GameModel::removeItem(Item item){
    Slots playerSlots = getCharacter()->getItemSlots();
    playerSlots.remove(std::move(item));
    currentUser.getCharacter()->setSlots(playerSlots);
}

void GameModel::dropItem(int positionKey){
    Slots playerSlots = getCharacter()->getItemSlots();
    playerSlots.drop(positionKey);
    currentUser.getCharacter()->setSlots(playerSlots);
}

void GameModel::pickupItem(Item item){
    Slots playerSlots = getCharacter()->getItemSlots();
    playerSlots.store(item);
    currentUser.getCharacter()->setSlots(playerSlots);
}

void GameModel::wearItem(Item item, int positionKey){
    Slots playerSlots = getCharacter()->getItemSlots();
    playerSlots.wear(std::move(item), positionKey);
    currentUser.getCharacter()->setSlots(playerSlots);
}















