/*
 *  Text Adventure
 *  By James Cranston (s3609326) & Justin Gerussi (s3644927)
 *
 */
#ifndef TEXTADVENTURE_CPP_DOOR_H
#define TEXTADVENTURE_CPP_DOOR_H

#include <boost/serialization/access.hpp>
#include "../../enums/direction.h"

using namespace std;

class Exit {

private:
    int fromRoom;
    int toRoom;
    Directions::Direction direction;
    bool roomIsOpen;

public:
    Exit();
    Exit(int fromRoom, int toRoom, Directions::Direction direction, bool doorIsOpen);

    int getToRoom();
    int getFromRoom();
    bool getRoomIsOpen();
    void setRoomIsOpen(bool status);
    void setDirection(Directions::Direction directionSelected);
    Directions::Direction getDirection();
    string getDirectionToString();

    friend class boost::serialization::access;

    template<typename Archive>
    void serialize(Archive& archive, const unsigned version){
        archive & fromRoom & toRoom & direction & roomIsOpen;
    }
};


#endif
