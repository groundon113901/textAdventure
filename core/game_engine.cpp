/*
 *  Text Adventure
 *  By James Cranston (s3609326) & Justin Gerussi (s3644927)
 *
 */
#include "headers/game_engine.h"

[[noreturn]] GameEngine::GameEngine(bool loadAscii, boost::filesystem::path dir) {
    model = loadData(loadAscii, dir);
    controller = GameController(model, view, dir);

    view.welcomePlayer();

   while(!controller.isLoggedIn()){
     vector<string> creds = view.loginScreen();
     controller.attemptLogin(creds);

     if(!controller.isLoggedIn()){
        view.loginFailed();
     }
   }

    cout << "Welcome " << controller.getCurrentUser()->getUsername() << "!" << endl;



    //start move regen ( 1 per second thread)
    controller.startMoveRegen();

    controller.look();
    while(true){
        cout << endl << "What would you like to do: " << endl;
        InputReader reader = InputReader();
        vector<string> cmdParts = reader.commandSplit(reader.readInput());
        Actions::Action action = reader.determineAction(cmdParts[0]);
        controller.handleAction(action, cmdParts);
    }


}


GameModel GameEngine::loadData(const bool loadAscii, const boost::filesystem::path dir) {
    DataReader dataReader = DataReader(dir);
    GameModel model;
    if(loadAscii) {
        model = dataReader.loadAsciiDataSet();
    }else{
        model = dataReader.loadBinaryDataSet();
    }

    return model;
}


