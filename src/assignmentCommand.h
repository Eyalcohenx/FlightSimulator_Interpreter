//
// Created by eyal on 19/12/18.
//

#ifndef FLIGHTPROJECTA_ASSIGNMENTCOMMAND_H
#define FLIGHTPROJECTA_ASSIGNMENTCOMMAND_H


#include "Command.h"
#include <string>
class assignmentCommand : public Command{
public:
    int execute(int index, vector<string> Tokens) override;
    ~assignmentCommand() override;
};


#endif //FLIGHTPROJECTA_ASSIGNMENTCOMMAND_H
