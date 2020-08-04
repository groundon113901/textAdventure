/*
 *  Text Adventure
 *  By James Cranston (s3609326) & Justin Gerussi (s3644927)
 *
 */
#ifndef TEXTADVENTURE_CPP_ACTIONS_H
#define TEXTADVENTURE_CPP_ACTIONS_H

#include <string>
#include <list>

using namespace std;
class Actions {
public:
    enum Action {
        N,
        E,
        S,
        W,
        PICKUP,
        WEAR,
        REMOVE,
        DROP,
        SAVE,
        LOOK,
        AREAS,
        EXITS,
        QUIT,
        OPEN,
        CLOSE,
        INVENTORY,
        INVALID = -1
    };

    static list<string> getEnumValues() {
        list<string> values;
        values.emplace_back("n");
        values.emplace_back("e");
        values.emplace_back("s");
        values.emplace_back("w");
        values.emplace_back("pickup");
        values.emplace_back("wear");
        values.emplace_back("remove");
        values.emplace_back("drop");
        values.emplace_back("save");
        values.emplace_back("look");
        values.emplace_back("areas");
        values.emplace_back("exits");
        values.emplace_back("quit");
        values.emplace_back("open");
        values.emplace_back("close");
        values.emplace_back("inventory");
        return values;
    }

    Action getEnum(string s){
        if (s == "n"){
            return N;
        } else if (s == "e"){
            return E;
        } else if (s == "s"){
            return S;
        } else if (s == "w"){
            return W;
        } else if (s == "pickup"){
            return PICKUP;
        } else if (s == "wear"){
            return WEAR;
        } else if (s== "remove"){
            return REMOVE;
        } else if (s == "drop"){
            return DROP;
        } else if (s == "save"){
            return SAVE;
        } else if (s == "look"){
            return LOOK;
        } else if (s == "areas"){
            return AREAS;
        } else if (s == "exits"){
            return EXITS;
        } else if (s == "quit"){
            return QUIT;
        } else if (s == "open"){
            return OPEN;
        } else if (s == "close"){
            return CLOSE;
        } else if (s == "inventory"){
            return INVENTORY;
        }
        else {
            return INVALID;
        }
    }
};
#endif
