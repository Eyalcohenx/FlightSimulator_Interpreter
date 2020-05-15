
#ifndef FLIGHTPROJECT_MINUS_H
#define FLIGHTPROJECT_MINUS_H


#include "Expression.h"
#include "Number.h"
#include <string>

class Minus : public Expression{
public:

    Minus(const Number &n1, const Number &n2);
    double calculate();

private:
    Number n1;
    Number n2;
};



#endif //FLIGHTPROJECT_MINUS_H
