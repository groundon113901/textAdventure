/*
 *  Text Adventure
 *  By James Cranston (s3609326) & Justin Gerussi (s3644927)
 *
 */
#ifndef TEXTADVENTURE_CPP_INPUT_READER_H
#define TEXTADVENTURE_CPP_INPUT_READER_H

#include <string>
#include <string_view>
#include <iostream>
#include <vector>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>
#include "../../model/enums/actions.h"

using namespace std;

class InputReader {
private:

public:
    string readInput();
    Actions::Action determineAction(string&);
    vector<string> commandSplit(string);
    void toLowerCase(string &str);
};


#endif
