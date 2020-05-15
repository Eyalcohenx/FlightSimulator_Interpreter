#ifndef FLIGHTPROJECT_DIV_H
#define FLIGHTPROJECT_DIV_H

#include "Expression.h"
#include "Number.h"
#include <string>

class Div : public Expression{
public:

    Div(const Number &n1, const Number &n2);
    double calculate();

private:
    Number n1;
    Number n2;
};

#endif //FLIGHTPROJECT_DIV_H
