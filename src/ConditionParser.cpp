//
// Created by eyal on 19/12/18.
//

#include "ConditionParser.h"
#include "ParserClass.h"

bool ConditionParser::CalculateCondition(vector<string> Tokens) {
    vector<string> left;
    vector<string> right;
    string condition;
    int conditionCounter = 0;
    // checking the sign condition
    for (auto token : Tokens)
    {
        if (token == "<"){
            condition = token;
            conditionCounter++;
        }else if(token == ">"){
            condition = token;
            conditionCounter++;
        }else if(token == "<="){
            condition = token;
            conditionCounter++;
        }else if(token == ">="){
            condition = token;
            conditionCounter++;
        }else if (token == "!="){
            condition = token;
            conditionCounter++;
        }else if(token == "=="){
            condition = token;
            conditionCounter++;
        }
    }

    //checking if there is mre then one condition
    if(conditionCounter != 1)
        throw "more or less than one condition";

    //separating the conditions to first and second
    int firstExpCounter = 0;
    while(Tokens.at(firstExpCounter) != condition){
        left.emplace_back(Tokens.at(firstExpCounter));
        firstExpCounter++;
    }
    firstExpCounter++;
    while(firstExpCounter != Tokens.size()){
        right.emplace_back(Tokens.at(firstExpCounter));
        firstExpCounter++;
    }

    // returning the boolean answer  to the condition
    if (condition == "<"){
        return (ParserClass::calculateExpression(left) < ParserClass::calculateExpression(right));
    }else if(condition == ">"){
        return (ParserClass::calculateExpression(left) > ParserClass::calculateExpression(right));
    }else if(condition == "<="){
        return (ParserClass::calculateExpression(left) <= ParserClass::calculateExpression(right));
    }else if(condition == ">="){
        return (ParserClass::calculateExpression(left) >= ParserClass::calculateExpression(right));
    }else if (condition == "!="){
        return (ParserClass::calculateExpression(left) != ParserClass::calculateExpression(right));
    }else{
        return (ParserClass::calculateExpression(left) == ParserClass::calculateExpression(right));
    }
}

