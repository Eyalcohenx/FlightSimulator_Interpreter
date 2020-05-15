//
// Created by vollin on 19/12/18.
//

#include "Mul.h"

Mul::Mul(const Number &n1, const Number &n2) : n1(n1), n2(n2) {}

double Mul::calculate() {
    return (n1).calculate() * (n2).calculate();
}