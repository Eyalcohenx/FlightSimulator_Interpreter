//
// Created by eyal on 19/12/18.
//

#ifndef FLIGHTPROJECTA_CONNECTCOMMAND_H
#define FLIGHTPROJECTA_CONNECTCOMMAND_H


#include "Command.h"

class ConnectCommand : public Command {
public:
    int execute(int index, vector<string> Tokens) override;
    ~ConnectCommand() override;
};


#endif //FLIGHTPROJECTA_CONNECTCOMMAND_H
