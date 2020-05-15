//
// Created by eyal on 19/12/18.
//

#ifndef FLIGHTPROJECTA_PRINTCOMMAND_H
#define FLIGHTPROJECTA_PRINTCOMMAND_H


#include "Command.h"

class printCommand : public Command{
public:
    int execute(int index, vector<string> Tokens) override;

    ~printCommand() override;
};


#endif //FLIGHTPROJECTA_PRINTCOMMAND_H
