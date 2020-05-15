//
// Created by eyal on 19/12/18.
//

#include "LexerClass.h"

//method to use in the lexing operation, can see its uses in the lexed class
//in the big string replaces the from string to to.
void LexerClass::ReplaceAll(string &str, const string& from, const string& to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
    }
}

//saving quatation in anoter place so the lexer will not effect its value
queue<string> LexerClass::SaveQuotations(string &str){

    //initializing varialbes
    queue<string> quotations;
    unsigned int start = 0;
    unsigned int finish = 0;
    bool inQuotationMark = false;

    //loop to save the quotations in a vector will be returned later
    for(unsigned int i = 0; i<str.length();i++) {
        if (str.at(i) == '"') {
            inQuotationMark = !inQuotationMark;
            if (inQuotationMark)
                start = i;
            else {
                finish = i;
                quotations.push(str.substr(start, finish - start + 1));
                for(unsigned j = start; j <= finish; j++)
                    str.at(j) = '#';
            }
        }
    }

    //throwing exception if one of the quotation did'nt close
    if(inQuotationMark){
        throw "did not cose quotation marks";
    }

    // returning the vector of quotations
    return  quotations;
}


vector<string> LexerClass::Lexer(string input){

    //saving quotations
    queue<string> quotations = SaveQuotations(input);

    //fixing the input and adding spaces in the right locations
    ReplaceAll(input,"("," ( ");
    ReplaceAll(input,")"," ) ");
    ReplaceAll(input,"["," [ ");
    ReplaceAll(input,"]"," ] ");
    ReplaceAll(input,"{"," { ");
    ReplaceAll(input,"}"," } ");
    ReplaceAll(input,"*"," * ");
    ReplaceAll(input,"/"," / ");
    ReplaceAll(input,"+"," + ");
    ReplaceAll(input,"="," = ");
    ReplaceAll(input,"<"," < ");
    ReplaceAll(input,">"," > ");
    ReplaceAll(input,"!"," ! ");
    ReplaceAll(input,"-"," - ");
    ReplaceAll(input,"–"," - ");
    ReplaceAll(input,","," , ");
    ReplaceAll(input,"=  ="," == ");
    ReplaceAll(input,"<  ="," <= ");
    ReplaceAll(input,">  ="," >= ");
    ReplaceAll(input,"!  ="," != ");


    //putting the string
    istringstream iss(input);
    string token;
    vector<string> take_chunks;

    //
    while(iss >> token){
        if(token.at(0) == '#')
        {
            //putting the quotations back
            take_chunks.emplace_back(quotations.front());
            quotations.pop();
        }
        else
            {
            take_chunks.emplace_back(token);
            }
    }

    //returning the tokens
    return take_chunks;
}
