/*
 *  Text Adventure
 *  By James Cranston (s3609326) & Justin Gerussi (s3644927)
 *
 */
#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/program_options.hpp>
#include "core/headers/program_options.h"
#include "core/headers/game_object.h"
#include "core/headers/game_engine.h"

using namespace std;
using namespace boost::filesystem;

int main(int argc, char * argv[]){
    variables_map vm = registerProgramOptions(argc, argv);
    bool isAscii = validateCommandLineInput(vm);
    boost::filesystem::path gameFolder = getGameDataPath(vm);

    GameEngine engine = GameEngine(isAscii, gameFolder);
}


