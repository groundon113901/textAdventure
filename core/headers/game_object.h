/*
 *  Text Adventure
 *  By James Cranston (s3609326) & Justin Gerussi (s3644927)
 *
 */
#ifndef TEXTADVENTURE_CPP_GAMEOBJECT_H
#define TEXTADVENTURE_CPP_GAMEOBJECT_H

#include <string>
#include <string_view>

using namespace std;
class GameObject{

protected:
    int id;
    string name;
    string description;

public:
    GameObject();//allow "Null" returns;
    GameObject(int, string, string);
    int getId();
    string getName();
    string getDescription();


};


#endif
