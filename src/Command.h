//
// Created by eyal on 19/12/18.
//

#ifndef FLIGHTPROJECTA_COMMAND_H
#define FLIGHTPROJECTA_COMMAND_H

#include <string>
#include <queue>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;
class Command
{
public:
    //execute gets the vector the parser is working on and the index we are currenty working on
    virtual int execute(int index, vector<string> Tokens) = 0;
    virtual ~Command()=0;
};
inline Command::~Command() {};



#endif //FLIGHTPROJECTA_COMMAND_H
