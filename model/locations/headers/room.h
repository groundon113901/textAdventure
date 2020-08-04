/*
 *  Text Adventure
 *  By James Cranston (s3609326) & Justin Gerussi (s3644927)
 *
 */
#ifndef TEXTADVENTURE_CPP_ROOM_H
#define TEXTADVENTURE_CPP_ROOM_H
#include "../../../core/headers/game_object.h"
#include "../../characters/headers/enemy.h"
#include "../../enums/direction.h"
#include "../../items/headers/item.h"
#include "exit.h"
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

class Room : public GameObject {

private:
   int areaId;
   int areaRoomId;
   vector<Enemy> enemies;
   map<Directions::Direction, Exit> adjacentRooms;
   vector<Item> items;
public:
    Room();
    Room(int id, string name, string description, int areaId, int areaRoomId, vector<Item>);
    int getAreaId();
    int getAreaRoomId();
    vector<Enemy> getEnemies();
    map<Directions::Direction, Exit> getRoomExits();
    static map<int, Room> getRooms(const map<int, Room>&, int);
    vector<Item> getItems();
    void setItems(vector<Item> item);
    void addItem(Item item);
    void removeItem(Item item);
    int getItemCount();
    void setEnemies(vector<Enemy> enemy);
    void setRoomExits(map<Directions::Direction, Exit> adjacentRoom);

    friend class boost::serialization::access;

    template<typename Archive>
    void serialize(Archive& archive, const unsigned version){
        archive & id & name & description & areaId & areaRoomId & items & adjacentRooms;
    }

};


#endif
