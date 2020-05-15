//
// Created by eyal on 20/12/18.
//

#ifndef FLIGHTPROJECTA_DATAREADERSERVER_H
#define FLIGHTPROJECTA_DATAREADERSERVER_H

#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sstream>

#include <string.h>
#include <string>
#include <iostream>
using namespace std;

struct ServerDetails
{
    int portno;
    int hz;
};

class DataReaderServer {
public:
    static bool stillWorking;
    static void CreateServerThread(int, int);
private:
    static void* createServer(void*);

};

#endif //FLIGHTPROJECTA_DATAREADERSERVER_H
