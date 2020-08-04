/*
 *  Text Adventure
 *  By James Cranston (s3609326) & Justin Gerussi (s3644927)
 *
 */
#ifndef TEXTADVENTURE_CPP_DATA_READER_H
#define TEXTADVENTURE_CPP_DATA_READER_H

#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/serialization.hpp>
#include <boost/filesystem/path.hpp>
#include <fstream>
#include <iterator>
#include <sstream>
#include <vector>
#include "../../model/user/headers/user.h"
#include "../../model/characters/headers/player_character.h"
#include "../../model/item_slots/headers/slots.h"
#include "../../model/locations/headers/room.h"
#include "../../model/locations/headers/area.h"
#include "../../model/game/headers/game_model.h"
#include "../../utility/headers/helpers.h"


using namespace std;
using namespace boost;


class DataReader {
private:
    boost::filesystem::path dataDir;

public:
    DataReader();
    DataReader(boost::filesystem::path);
    vector<vector<string>> readLines(boost::filesystem::path);
    map<string, User> loadUsers(GameModel *pModel);
    map<int, Item> loadItems();
    map<int, Room> loadRooms(GameModel*);
    static void scatterItems(map<int, Room>*, GameModel*);
    map<int, Area> loadAreas(map<int, Room>);
    map<pair<int, int>, Exit> loadExits();
    GameModel loadAsciiDataSet();
    GameModel loadBinaryDataSet();


};


#endif