#ifndef FLIGHTPROJECTA_TCP_CLIENT_H
#define FLIGHTPROJECTA_TCP_CLIENT_H

#include<iostream>	//cout
#include<stdio.h>	//printf
#include<string.h>	//strlen
#include<string>	//string
#include<sys/socket.h>	//socket
#include<arpa/inet.h>	//inet_addr
#include<netdb.h>	//hostent

using namespace std;

/**
	TCP Client class
*/
class TCPClient
{
private:
    int sock;
    std::string address;
    int port;
    struct sockaddr_in server;

public:
    TCPClient();
    bool conn(string, int);
    bool send_data(string data);
    string receive(int);
};



#endif //FLIGHTPROJECTA_TCP_CLIENT_H
