//
// Created by eyal on 19/12/18.
//

#ifndef FLIGHTPROJECTA_LOOKCOMMAND_H
#define FLIGHTPROJECTA_LOOKCOMMAND_H

#include "ConditionParser.h"

class loopCommand : public ConditionParser {
    int execute(int index, vector<string> Tokens) override;
    ~loopCommand() override;
};



#endif //FLIGHTPROJECTA_LOOKCOMMAND_H
