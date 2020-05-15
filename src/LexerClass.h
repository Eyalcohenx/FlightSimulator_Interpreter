//
// Created by eyal on 19/12/18.
//

#ifndef FLIGHTPROJECTA_LEXERCLASS_H
#define FLIGHTPROJECTA_LEXERCLASS_H


#include <string>
#include <queue>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class LexerClass {
    static void ReplaceAll(string &str, const string& from, const string& to);
    static queue<string> SaveQuotations(string &str);
public:
    static vector<string> Lexer(string input);
};


#endif //FLIGHTPROJECTA_LEXERCLASS_H
