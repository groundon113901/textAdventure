/*
 *  Text Adventure
 *  By James Cranston (s3609326) & Justin Gerussi (s3644927)
 *
 */
#ifndef TEXTADVENTURE_CPP_ITEM_H
#define TEXTADVENTURE_CPP_ITEM_H

#include <boost/serialization/access.hpp>
#include "../../../core/headers/game_object.h"

using namespace std;

class Item : public GameObject {

public:
    enum WearPosition{ HEAD, ARMS, HANDS, TORSO, WRISTS, LEGS, FEET, WEAPON, SHIELD };
    static WearPosition positionFromString(string&);
    static string wearPositionToString(WearPosition);
    Item(int id, string name, string description, int value, WearPosition position);
    Item(); //allow "Null" returns;
    string getDescription();
    int getValue();
    WearPosition getWearPosition();
    bool operator ==(const Item &i1);
    friend class boost::serialization::access;

    template<typename Archive>
    void serialize(Archive& archive, const unsigned version){
        archive & id & name & description & value & wearPosition;
    }



protected:
    int value;
    WearPosition wearPosition;

};


#endif
