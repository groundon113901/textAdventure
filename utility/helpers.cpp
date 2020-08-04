/*
 *  Text Adventure
 *  By James Cranston (s3609326) & Justin Gerussi (s3644927)
 *
 */

#include "headers/helpers.h"

int Helper::randomZeroToN(unsigned long long n){
    random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<int> distribution(0, n);
    return distribution(generator);
}

string Helper::stringFromVector(vector<string> input){
    string str;
    size_t count = 1;

    for (const string&  s : input){
        if (s != input[0]){
            if (count != input.size() - 1) {
                str.append(s + " ");
                count++;
            }else {
                str.append(s);
            }
        }
    }


    return str;
}

size_t Helper::partialMatch(string searchStr, string elem){
    boost::to_lower(elem);
    boost::to_lower(searchStr);
    return elem.find(searchStr);
}