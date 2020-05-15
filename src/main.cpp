#include <iostream>
#include <vector>
#include <fstream>
#include "LexerClass.h"
#include "ParserClass.h"
#include "symTblClass.h"
#include "DataReaderServer.h"


//initializing needed variables
vector<string> Lexed;
string input = "";
ifstream myReadFile;
string CommandsFromFile;
string FilePath;
string nextLine;

using namespace std;


int main (int argc,  char **argv) {
    string FilePath(argv[1]);
    myReadFile.open(FilePath);

    if (myReadFile.is_open()) {
        //putting all the text from file to one long string
        while (!myReadFile.eof()) {
            getline(myReadFile, nextLine);
            CommandsFromFile += " " + nextLine;
        }

        //lexing the commands from file
        myReadFile.close();
        Lexed = LexerClass::Lexer(CommandsFromFile);
        ParserClass::Parser(Lexed);
        CommandsFromFile = "";

        DataReaderServer::stillWorking = false;

        sleep(3);
        return 0;
    }
}

