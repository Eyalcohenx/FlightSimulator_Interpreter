//
// Created by eyal on 19/12/18.
//

#ifndef FLIGHTPROJECTA_SLEEPCOMMAND_H
#define FLIGHTPROJECTA_SLEEPCOMMAND_H


#include "Command.h"

class sleepCommand : public Command{
public:
    int execute(int index, vector<string> Tokens) override;

    ~sleepCommand() override;
};


#endif //FLIGHTPROJECTA_SLEEPCOMMAND_H
