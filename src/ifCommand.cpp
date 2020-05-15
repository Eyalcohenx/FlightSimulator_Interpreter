//
// Created by eyal on 19/12/18.
//

#include "ifCommand.h"
#include "ParserClass.h"

ifCommand::~ifCommand()=default;

int ifCommand::execute(int index, vector<string> Tokens) {

    //counter to return to parser
    int counter = 1;
    index++;

    //initializing the expressions
    vector<string> commands = {};
    vector<string> condition = {};

    // puttng the condition in another vector
    while (index < Tokens.size() && Tokens.at(index) != "{"){
        condition.emplace_back(Tokens.at(index));
        counter++;
        index++;
    }
    counter++;
    index++;

    //putting the commands in the brackets in a different vector
    while (index < Tokens.size() && Tokens.at(index) != "}"){
        commands.emplace_back(Tokens.at(index)); // puttng the commands in another vector
        counter++;
        index++;
    }

    //checking if the brackets was closed
    if(index == Tokens.size()-1 && Tokens.at(index) != "}")
        throw "did not close brackets }";
    counter++;

    //executing the commands in the brackets
    if(ConditionParser::CalculateCondition(condition)){
        ParserClass::Parser(commands);
    }

    //returning how many spots to move next
    return counter;
}
