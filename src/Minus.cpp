//
// Created by vollin on 19/12/18.
//

#include "Minus.h"

Minus::Minus(const Number &n1, const Number &n2) : n1(n1), n2(n2) {}

double Minus::calculate() {
    return (n1).calculate() - (n2).calculate();
}