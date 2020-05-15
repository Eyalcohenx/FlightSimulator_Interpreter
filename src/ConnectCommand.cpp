//
// Created by eyal on 19/12/18.
//

#include <sys/socket.h>
#include "ConnectCommand.h"
#include "ParserClass.h"
#include "symTblClass.h"

int ConnectCommand::execute(int index, vector<string> Tokens) {
    index++;
    int counter = 1;
    string ip = Tokens.at(index);

    //checks the ip if its valid
    for(auto c : ip){
        if(!isdigit(c) && c != '.')
            throw "not a valid ip";
    }

    //getting the expression
    vector<string> expression = ParserClass::get1Expression(index,Tokens);
    counter += expression.size()+1;

    //connecting t the desired socket
    symTblClass::client.conn(ip,(int) ParserClass::calculateExpression(expression));

    return counter;
}

ConnectCommand::~ConnectCommand() {}
