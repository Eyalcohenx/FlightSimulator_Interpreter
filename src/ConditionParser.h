//
// Created by eyal on 19/12/18.
//

#ifndef FLIGHTPROJECTA_CONDITIONPARSER_H
#define FLIGHTPROJECTA_CONDITIONPARSER_H

#include "Command.h"

class ConditionParser : public Command{
public:
    static bool CalculateCondition(vector<string>);
};


#endif //FLIGHTPROJECTA_CONDITIONPARSER_H
