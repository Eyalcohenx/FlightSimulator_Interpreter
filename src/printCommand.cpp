//
// Created by eyal on 19/12/18.
//

#include "printCommand.h"
#include "ParserClass.h"
#include "symTblClass.h"

int printCommand::execute(int index, vector<string> Tokens) {
    // from print -> "..."
    index++;

    //if and else to ckeck if its print "qoutation" or print expression
    if(ParserClass::isQuotation(Tokens.at(index))){
        cout << Tokens.at(index).substr(1,Tokens.at(index).length()-2) << endl;
        return 2;
    }else{
        vector<string> expression = ParserClass::get1Expression(index-1,Tokens);
        double print = ParserClass::calculateExpression(expression);
        cout << print << endl;
        return expression.size()+1;
    }

}

printCommand::~printCommand() {

}
