//
// Created by eyal on 19/12/18.
//

#include <unistd.h>
#include "sleepCommand.h"
#include "ParserClass.h"

int sleepCommand::execute(int index, vector<string> Tokens) {
    int counter = 1;
    vector<string> expression = ParserClass::get1Expression(index, Tokens);
    counter += expression.size();
    int timeToSleep = (int) (ParserClass::calculateExpression(expression)/1000);
    sleep(timeToSleep);
    return counter;
}

sleepCommand::~sleepCommand() {}
