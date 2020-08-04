/*
 *  Text Adventure
 *  By James Cranston (s3609326) & Justin Gerussi (s3644927)
 *
 */
#ifndef TEXTADVENTURE_CPP_PROGRAM_OPTIONS_H
#define TEXTADVENTURE_CPP_PROGRAM_OPTIONS_H

#include <iostream>
#include <boost/program_options.hpp>

using namespace std;
using namespace boost::program_options;

variables_map registerProgramOptions(int argc, char **argv) {
    options_description description("Options");
    description.add_options()
            ("ascii_data", value<boost::filesystem::path>(), "Provide the path for ASCII game data")
            ("binary_data", value<boost::filesystem::path>(), "Provide the path for binary game data");

    variables_map vm;
    store(parse_command_line(argc, argv, description), vm);
    notify(vm);
    return vm;
}

bool verifyFolderPath(boost::filesystem::path aPath) {
    if(boost::filesystem::exists(aPath)){
        return true;
    }else{
        cout << "Provided file path does not exist" << endl;
        return EXIT_FAILURE;
    }
}

/* Function to verify the command line inputs are valid arguments
** returns true if is Ascii and false if binary (to use in isAscii)
*/
bool validateCommandLineInput(variables_map vm){
   if(vm.count("binary_data") && vm.count("ascii_data")){
       cout << "Use of binary or ascii data is mutually exclusive" << endl;
       return EXIT_FAILURE;
   }

   if(vm.count("ascii_data")){
       if(verifyFolderPath(vm["ascii_data"].as<boost::filesystem::path>())){
           return true;
       }
   }

   if(vm.count("binary_data")){
       if(verifyFolderPath(vm["binary_data"].as<boost::filesystem::path>())){
           return false;
       }
   }

    cout << "Invalid program option provided" << endl;
    return EXIT_FAILURE;

}

boost::filesystem::path getGameDataPath(variables_map vm){
    if(vm.count("ascii_data")){
        return vm["ascii_data"].as<boost::filesystem::path>();
    }
    if(vm.count("binary_data")){
        return vm["binary_data"].as<boost::filesystem::path>();
    }

    return boost::filesystem::path();
}

#endif //TEXTADVENTURE_CPP_PROGRAM_OPTIONS_H
