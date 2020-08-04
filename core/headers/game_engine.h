/*
 *  Text Adventure
 *  By James Cranston (s3609326) & Justin Gerussi (s3644927)
 *
 */
#ifndef TEXTADVENTURE_CPP_GAMEENGINE_H
#define TEXTADVENTURE_CPP_GAMEENGINE_H

#include <map>
#include <boost/filesystem.hpp>
#include "data_reader.h"
#include "../../view/headers/game_view.h"
#include "../../controller/headers/game_controller.h"
#include "../../model/game/headers/game_model.h"
#include "../../model/user/headers/user.h"
#include "../../model/items/headers/item.h"
#include "../../model/locations/headers/room.h"
#include "../../model/locations/headers/area.h"

using namespace std;
using namespace boost;

class GameEngine {
private:
    GameView view;
    GameController controller;
    GameModel model;

public:
    [[noreturn]] GameEngine(bool, boost::filesystem::path);
    GameModel loadData(bool, boost::filesystem::path);
};


#endif
