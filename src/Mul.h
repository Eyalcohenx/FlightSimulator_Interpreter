//
// Created by vollin on 19/12/18.
//

#ifndef FLIGHTPROJECT_MUL_H
#define FLIGHTPROJECT_MUL_H

#include "Expression.h"
#include "Number.h"
#include <string>

class Mul : public Expression{
public:

    Mul(const Number &n1, const Number &n2);
    double calculate();

private:
    Number n1;
    Number n2;
};

#endif //FLIGHTPROJECT_MUL_H
