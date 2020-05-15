//
// Created by eyal on 19/12/18.
//

#ifndef FLIGHTPROJECTA_IFCOMMAND_H
#define FLIGHTPROJECTA_IFCOMMAND_H

#include "ConditionParser.h"

class ifCommand : public ConditionParser{
public:
    ~ifCommand() override;
    int execute(int index, vector<string> Tokens) override;
};


#endif //FLIGHTPROJECTA_IFCOMMAND_H
