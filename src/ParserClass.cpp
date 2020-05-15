#include "ParserClass.h"
#include "symTblClass.h"
#include "ConditionParser.h"
#include "ifCommand.h"
#include "assignmentCommand.h"
#include "printCommand.h"
#include "OpenServerCommand.h"
#include "ConnectCommand.h"
#include "sleepCommand.h"
#include "loopCommand.h"
#include "Number.h"
#include "Plus.h"
#include "Minus.h"
#include "Mul.h"
#include "Div.h"
#include "LexerClass.h"


void ParserClass::Parser(vector<string> Tokens){
    //intislizing commands map
    map<string,Command*> Commands;
    Commands["var"] = new DefineVarCommand();
    Commands["if"] = new ifCommand();
    Commands["while"] = new loopCommand();
    Commands["="] = new assignmentCommand();
    Commands["print"] = new printCommand();
    Commands["openDataServer"] = new OpenServerCommand();
    Commands["connect"] = new ConnectCommand();
    Commands["sleep"] = new sleepCommand();

    //parsing the input
    for(int index = 0; index < Tokens.size();) {
        if(isCommand(Tokens.at(index)))
            index += Commands[Tokens.at(index)]->execute(index,Tokens);
        else if(symTblClass::isSym(Tokens.at(index))) {
            index++;
        } else{
            throw "unknown command";
        }
    }

    // deleting all the pointers to the commands
    delete Commands["var"];
    delete Commands["if"];
    delete Commands["while"];
    delete Commands["="];
    delete Commands["print"];
    delete Commands["openDataServer"];
    delete Commands["connect"];
    delete Commands["sleep"];
}

//method to check if a string is a command
bool ParserClass::isCommand(const string &str) {
    vector<string> Commands = {"var"
                               ,"if"
                               ,"while"
                               ,"="
                               ,"print"
                               ,"openDataServer"
                               ,"connect"
                               ,"sleep"};

    //iterating the vector and cheking if the inout exist there
    for(auto com : Commands){
        if(str == com)
            return true;
    }
    return false;
}

//checking if a string is a pure number
bool ParserClass::isNumber(const string str) {
    double doub;
    istringstream iss(str);
    return (!(iss >> doub).fail());//retruns true if its a number
}

//checking if a string is a quotation
bool ParserClass::isQuotation(const string str) { //checks if a expression is a string
    if(str.at(0) == '"' && str.at(str.length()-1) == '"')
        return true;
    if(str.at(0) == '"' && str.at(str.length()-1) != '"')
        throw "starts with quoutation mark but doesnt end";
    if(str.at(0) != '"' && str.at(str.length()-1) == '"')
        throw "ends with quoutation mark but doesnt starts with one";
    return false;
}


// returns the 1 expression after command or after '='
vector<string> ParserClass::get1Expression(const int index, vector<string>Tokens) {
    int ind = index;
    ind++;
    vector<string> expression = {};
    string check = "";

    try{
        check = Tokens.at(ind+1);
    }catch(...){};
    while(ind < Tokens.size() && Tokens.at(ind) != "}" && !isCommand(Tokens.at(ind)) && !(symTblClass::isSym(Tokens.at(ind)) && check == "=")){
        expression.emplace_back(Tokens.at(ind));
        ind++;
        try{
            check = Tokens.at(ind+1);
        }catch(...){check = "";};
    }
    return expression;
}

bool ParserClass::isOperator(string str){
    if(str == "+" || str == "-" || str == "/" || str == "*" || str == "(")
        return true;
    return false;
}


double ParserClass::calculateExpression(const vector<string> expression) {
    double temp;
    string removeMinus;
    vector<string> onlyNums;
    //loop  for replaceing the names for values
    for(int i=0; i<expression.size(); i++){
        if(symTblClass::isSym(expression.at(i)))
        {
            temp = symTblClass::getVlaue(expression.at(i));
            removeMinus = to_string(temp);
            if(removeMinus.at(0) == '-'){
                onlyNums.emplace_back("-");
                removeMinus = removeMinus.substr(1,removeMinus.length()-1);
            }
            onlyNums.emplace_back(removeMinus);
        }else {
            onlyNums.emplace_back(expression.at(i));
        }
    }

    // checking if the value we send is only numbers or operators
    for(auto str : onlyNums){
        if(!isNumber(str) && str != "+" && str != "-" && str != "*" && str != "/" && str != "(" && str != ")"){
            throw "one of the names is not a valid symbol";
        }
    }

    //sending to the evaluating algorithm
    return evaluate(onlyNums);
}

//method counting the lengto of the first expression for a command that needs 2 expressions like connect expression1 ,expression 2
int ParserClass::ExpressionLength(int index, vector<string> Tokens) {
    int counter = 1;
    while(index < Tokens.size() && !ParserClass::isCommand(Tokens.at(index)) && Tokens.at(index) != ","){
        if(ParserClass::isNumber(Tokens.at(index))){
            if(ParserClass::isNumber(Tokens.at(index+1)))
                return counter;
            else if(Tokens.at(index+1) == "(")
                return counter;
            else if(symTblClass::isSym(Tokens.at(index+1)))
                return counter;
        }
        else if(Tokens.at(index) == ")"){
            if(ParserClass::isNumber(Tokens.at(index+1)))
                return counter;
            else if(Tokens.at(index+1) == "(")
                return counter;
            else if(symTblClass::isSym(Tokens.at(index+1)))
                return counter;
        }
        else if(symTblClass::isSym(Tokens.at(index))){
            if(ParserClass::isNumber(Tokens.at(index+1)))
                return counter;
            else if(Tokens.at(index+1) == "(")
                return counter;
            else if(symTblClass::isSym(Tokens.at(index+1)))
                return counter;
        }
        index++;
        counter++;
    }

    return counter;
}


// Function to find precedence of
// operators.
int ParserClass::precedence(char op){
    if(op == '+'||op == '-')
        return 1;
    if(op == '*'||op == '/')
        return 2;
    return 0;
}

// Function to perform arithmetic operations.
double ParserClass::applyOp(double a, double b, char op){
    Number num1 = Number(a);
    Number num2 = Number(b);
    Plus plus = Plus(num1,num2);
    Minus minus = Minus(num1,num2);
    Mul mul = Mul(num1,num2);
    Div div = Div(num1,num2);

    switch(op){
        case '+': return plus.calculate();
        case '-': return minus.calculate();
        case '*': return mul.calculate();
        case '/': return div.calculate();
    }
}

// Function that returns value of
// expression after evaluation.
double ParserClass::evaluate(const vector<string> expression){
    vector<string> tok = expression;
    unsigned long int times = tok.size();
    vector<string> tempTok = {};
    string tokens="";
    for(int j = 0; j < times; j++){
        for(int i = 0; i < tok.size()-1; i++){
            if(tok.at(i) == "-"){
                 if(tok.at(i+1) == "-") {
                     tempTok.emplace_back("+");
                     i++;
                 }else if(tok.at(i+1) == "+") {
                     tempTok.emplace_back("-");
                     i++;
                 }else{
                     tempTok.emplace_back(tok.at(i));
                 }
            }else if(tok.at(i) == "+"){
                if(tok.at(i+1) == "-") {
                    tempTok.emplace_back("-");
                    i++;
                }else if(tok.at(i+1) == "+") {
                    tempTok.emplace_back("+");
                    i++;
                }else{
                    tempTok.emplace_back(tok.at(i));
                }
            }else{
                tempTok.emplace_back(tok.at(i));
            }
        }
        tempTok.emplace_back(tok.at(tok.size()-1));
        tok = tempTok;
        tempTok = {};
    }

    //taking care of the unary minus operator and plus operator
    if(tok.at(0) == "-" && (!isOperator(tok.at(1)) || tok.at(1) == "("))
        tokens=tokens + "0" + " " + "-" + " ";
    else if(tok.at(0) == "+" && (!isOperator(tok.at(1)) || tok.at(1) == "("))
        tokens=tokens + "0" + " " "+" + " ";
    else
        tokens = tokens + tok[0] + " ";
    for(int r=1;r<tok.size()-1;r++){
        if(tok.at(r) == "-" && isOperator(tok.at(r-1))){
            tokens=tokens + "0" + " " "-" + " ";
        }else if(tok.at(r) == "+" && isOperator(tok.at(r-1))){
            tokens=tokens + "0" + " " "+" + " ";
        }else {
            tokens = tokens + tok[r] + " ";
        }
    }

    tokens=tokens+tok.at(tok.size()-1);
    int i;

    // stack to store integer values.
    stack <double> values;

    // stack to store operators.
    stack <char> ops;

    for(i = 0; i < tokens.length(); i++){

        // Current token is a whitespace,
        // skip it.
        if(tokens[i] == ' ' )
            continue;

            // Current token is an opening
            // brace, push it to 'ops'
        else if(tokens[i] == '('){
            ops.push(tokens[i]);
        }

            // Current token is a number, push
            // it to stack for numbers.
        else if(isdigit(tokens[i]) ){
            int res = 0;
            double newVal = 0;
            int val = 0;
            int count = 0;
            // There may be more than one
            // digits in number.
            while(i < tokens.length() && isdigit(tokens[i])) {
                val = (val*10) + (tokens[i]-'0');
                i++;
            }
            if(tokens[i]=='.'){
                i++;
                while(i < tokens.length() && isdigit(tokens[i])){
                    count++;
                    res = (res*10) + (tokens[i]-'0');
                    i++;
                }
            }
            newVal = (double)val + ((double)res)/pow(10,count);
            values.push(newVal);
        }

            // Closing brace encountered, solve
            // entire brace.
        else if(tokens[i] == ')')
        {
            while(!ops.empty() && ops.top() != '(')
            {
                char op = ops.top();
                ops.pop();

                double val2 = values.top();
                values.pop();

                double val1 = 0;

                if(op != 'u' && op != 'b'){
                    val1 = values.top();
                    values.pop();
                }

                values.push(applyOp(val1, val2, op));
            }

            // pop opening brace.
            ops.pop();
        }

            // Current token is an operator.
        else
        {
            // While top of 'ops' has same or greater
            // precedence to current token, which
            // is an operator. Apply operator on top
            // of 'ops' to top two elements in values stack.
            while(!ops.empty() && precedence(ops.top()) >= precedence(tokens[i])){

                char op = ops.top();
                ops.pop();

                double val2 = values.top();
                values.pop();

                double val1 = 0;

                if(op != 'u' && op != 'b'){
                    val1 = values.top();
                    values.pop();
                }


                values.push(applyOp(val1, val2, op));
            }

            // Push current token to 'ops'.
            ops.push(tokens[i]);
        }
    }

    // Entire expression has been parsed at this
    // point, apply remaining ops to remaining
    // values.
    while(!ops.empty()){

        char op = ops.top();
        ops.pop();

        double val2 = values.top();
        values.pop();

        double val1 = 0;

        if(op != 'u' && op != 'b'){
            val1 = values.top();
            values.pop();
        }

        values.push(applyOp(val1, val2, op));
    }

    // Top of 'values' contains result, return it.
    return values.top();
}

