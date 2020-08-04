/*
 *  Text Adventure
 *  By James Cranston (s3609326) & Justin Gerussi (s3644927)
 *
 */
#include "headers/input_reader.h"


string InputReader::readInput(){
    string input;

    getline(cin, input);

    return input;
}

Actions::Action InputReader::determineAction(string& input) {
    list<string> values = Actions::getEnumValues();
    toLowerCase(input);
    int count = 0;
    Actions cmd;
    Actions::Action action = Actions::INVALID;
    for(const string&  s : values){
        size_t found = s.find(input);
        if (found == 0){
           if (s.length() == 1 || count == 0) {
               action = cmd.getEnum(s);
               count++;
           }
        }
    }
    return action;
}

vector<string> InputReader::commandSplit(string input) {
    vector<string> result;
    if(input.find(" ") == string::npos){
        result.emplace_back(input);
    }else{
        boost::split(result, input, boost::is_any_of(" "));
    }

    return result;
}

void InputReader::toLowerCase(string& str){
    for(char& c : str){
        c = tolower(c);
    }
}