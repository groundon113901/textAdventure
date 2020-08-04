/*
 *  Text Adventure
 *  By James Cranston (s3609326) & Justin Gerussi (s3644927)
 *
 */
#ifndef TEXT_ADVENTURE_GAME_MODEL_H
#define TEXT_ADVENTURE_GAME_MODEL_H

#include <boost/serialization/map.hpp>
#include <boost/serialization/vector.hpp>
#include "../../locations/headers/area.h"
#include "../../locations/headers/room.h"
#include "../../locations/headers/exit.h"
#include "../../items/headers/item.h"
#include "../../user/headers/user.h"
#include "../../enums/actions.h"

using namespace std;

class GameModel {
private:
    map<int, Area> areas;
    map<int, Room> rooms;
    map<pair<int, int>, Exit> exits;
    map<int, Item> items;
    map<string, User> users;
    User currentUser;

    bool isAsciiModel;
    int currentRoom;

public:
    GameModel();
    GameModel(User);

    void isAscii(bool);
    bool isAscii() const;

    /* User */
    void setUsers(map<string, User>);
    map<string, User> getUsers();
    void mergeCurrentUser();
    void setCurrentUser(User user);
    User* getUserByUsername(string);
    User* getCurrentUser();
    PlayerCharacter* getCharacter();
    void updateMoveCount(int);

    /* Area */
    void setAreas(map<int, Area>);
    map<int, Area> getAreas();
    Area getAreaById(int);
    vector<Room> getRoomsByArea(int);

    /* Room */
    void setRooms(map<int, Room>);
    void setCurrentRoom(int);
    map<int, Room> getRooms();
    Room getRoomById(int);
    void setRoomItems(int, vector<Item>);
    vector<Item> getRoomItems(int);
    map<Directions::Direction, Exit> getRoomExitsMap(int);
    void updateRoomExits(Exit exit);
    map<Directions::Direction, Exit> generateRoomExitsMap(int);

    /* Exit */
    void setExits(map<pair<int, int>, Exit>);
    map<pair<int,int>, Exit> getExits();
    Exit getExit(int, int);


    /* Item */
    void setItems(map<int, Item>);
    map<int, Item> getItems();
    Item getItemById(int);

    int getCurrentRoomId();

    void openOrCloseDoor(Exit exit, Actions::Action action);
    void removeItem(Item item);
    void updateItemSlots(Slots slots);
    void dropItem(int positionKey);
    void pickupItem(Item item);
    void wearItem(Item item, int positionKey);

    friend class boost::serialization::access;
    template<typename Archive>
    void serialize(Archive& archive, const unsigned version){
        archive & items & areas & rooms & exits & users;
    }

    void insertRoomItem(int i, Item item);


    void removeRoomItem(int i, Item item);
};


#endif //TEXT_ADVENTURE_GAME_MODEL_H
