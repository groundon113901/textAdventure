/*
 *  Text Adventure
 *  By James Cranston (s3609326) & Justin Gerussi (s3644927)
 *
 */
#ifndef TEXT_ADVENTURE_HELPERS_H
#define TEXT_ADVENTURE_HELPERS_H

#include <random>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>

using namespace std;

class Helper{
public:
        static int randomZeroToN(unsigned long long n);
        static string stringFromVector(vector<string> input);
        static size_t partialMatch(string searchStr, string elem);

};

#endif //TEXT_ADVENTURE_HELPERS_H
