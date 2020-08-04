/*
 *  Text Adventure
 *  By James Cranston (s3609326) & Justin Gerussi (s3644927)
 *
 */

#ifndef TEXTADVENTURE_CPP_DIRECTION_H
#define TEXTADVENTURE_CPP_DIRECTION_H

#include <string>
#include <list>

using namespace std;

class Directions{
public:
    enum Direction{
        NORTH,
        EAST,
        SOUTH,
        WEST,
        UP,
        DOWN,
        INVALID = -1
    };

    static Direction getFromString(string dir){
        if(dir == "NORTH" || dir == "north"){
            return NORTH;
        }else if(dir == "EAST" || dir == "east"){
            return EAST;
        }else if(dir == "SOUTH" || dir == "south"){
            return SOUTH;
        }else if(dir == "WEST" || dir == "west") {
            return WEST;
        }else if(dir == "UP" || dir == "up"){
            return UP;
        }else if(dir == "DOWN" || dir == "down") {
            return DOWN;
        }else {
            return INVALID;
        };
    }

    static list<string> getEnumValues() {
        list<string> values;
        values.emplace_back("north");
        values.emplace_back("east");
        values.emplace_back("south");
        values.emplace_back("west");
        values.emplace_back("up");
        values.emplace_back("down");
        return values;
    }
};

#endif
