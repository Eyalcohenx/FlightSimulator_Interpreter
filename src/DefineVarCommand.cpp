//
// Created by eyal on 19/12/18.
//

#include "DefineVarCommand.h"
#include "symTblClass.h"
#include "ParserClass.h"

//this execute just puts the symbol to the sybol table nothing else
int DefineVarCommand::execute(int index, vector<string> Tokens) {

    //check if doesnt starts with letter
    if(!(isalpha(Tokens.at(index+1).at(0))))
        throw("argument name must start with a letter");

    //trying to add the symbol to the symbol table
    if(symTblClass::addSym(Tokens.at(index+1))) {
        //if added successfully adding the symbol to the table
        //and returning how many spots to move next
        return 2;
    }
    else
        //if the value already inside the map we need to throw exception
        throw("alredy exist in map");
}

DefineVarCommand::~DefineVarCommand() {
}
