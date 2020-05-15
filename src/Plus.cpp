//
// Created by vollin on 18/12/18.
//

#include "Plus.h"

Plus::Plus(const Number &n1, const Number &n2) : n1(n1), n2(n2) {}

double Plus::calculate() {
    return (n1).calculate() + (n2).calculate();
}