//
// Created by eyal on 19/12/18.
//

#ifndef FLIGHTPROJECTA_OPENSERVERCOMMAND_H
#define FLIGHTPROJECTA_OPENSERVERCOMMAND_H


#include "Command.h"
#include <pthread.h>
#include <atomic>

class OpenServerCommand : public Command{
public:
    static atomic<int> connection_indicator; // 0 if not connected 1 if connected
    int execute(int index, vector<string> Tokens) override;
    ~OpenServerCommand() override;
};


#endif //FLIGHTPROJECTA_OPENSERVERCOMMAND_H
