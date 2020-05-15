//
// Created by eyal on 19/12/18.
//

#ifndef FLIGHTPROJECTA_DEFINEVARCOMMAND_H
#define FLIGHTPROJECTA_DEFINEVARCOMMAND_H


#include "Command.h"

class DefineVarCommand: public Command{

public:
    int execute(int index, vector<string> Tokens) override;

    ~DefineVarCommand() override;
};


#endif //FLIGHTPROJECTA_DEFINEVARCOMMAND_H
