//
// Created by vollin on 18/12/18.
//

#ifndef FLIGHTPROJECT_PLUS_H
#define FLIGHTPROJECT_PLUS_H

#include "Expression.h"
#include "Number.h"
#include <string>

class Plus : public Expression{
public:

    Plus(const Number &n1, const Number &n2);
    double calculate();

private:
    Number n1;
    Number n2;
};


#endif //FLIGHTPROJECT_PLUS_H
