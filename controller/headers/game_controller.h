/*
 *  Text Adventure
 *  By James Cranston (s3609326) & Justin Gerussi (s3644927)
 *
 */

#ifndef TEXT_ADVENTURE_GAME_CONTROLLER_H
#define TEXT_ADVENTURE_GAME_CONTROLLER_H

#include <thread>
#include <chrono>
#include <boost/filesystem/path.hpp>
#include "input_reader.h"
#include "../../core/headers/data_writer.h"
#include "../../model/game/headers/game_model.h"
#include "../../view/headers/game_view.h"
#include "../../utility/headers/helpers.h"

class GameController {
private:
    GameModel model;
    GameView view;
    boost::filesystem::path dataDir;
public:
    GameController();
    GameController(GameModel, GameView, boost::filesystem::path);
    GameModel& getModel();
    void handleAction(Actions::Action, vector<string>);
    void move(int);
    void wear(const vector<string>& input);
    void remove(const vector<string>& input);
    void drop(const vector<string>& input);
    void save(bool, const boost::filesystem::path&);
    void pickup(const vector<string>& input);
    void look();
    void areas();
    void exits();
    void quit();
    bool isLoggedIn();
    void attemptLogin(vector<string>);
    User* getCurrentUser();
    void startMoveRegen();
    void doorOpenORClose(vector<string> input, Actions::Action action);
    [[noreturn]] void moveRegen(GameModel&);




    void inventory();
};


#endif //TEXT_ADVENTURE_GAME_CONTROLLER_H
