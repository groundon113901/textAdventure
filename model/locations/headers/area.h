/*
 *  Text Adventure
 *  By James Cranston (s3609326) & Justin Gerussi (s3644927)
 *
 */
#ifndef TEXTADVENTURE_CPP_AREA_H
#define TEXTADVENTURE_CPP_AREA_H

#include <string>
#include <map>
#include "room.h"
using namespace std;

class Area : public GameObject {
private:
    map<int, Room> rooms;

public:
    Area();
    Area(int id, string name, string description, map<int, Room> rooms);
    void setRooms(map<int,Room>);
    void insertRoom(int num, const Room& room);
    map<int, Room> getRooms();

    friend class boost::serialization::access;

    template<typename Archive>
    void serialize(Archive& archive, const unsigned version){
        archive & id & name & description & rooms;
    }
};


#endif
