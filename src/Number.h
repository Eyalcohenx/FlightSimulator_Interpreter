//
// Created by vollin on 18/12/18.
//

#ifndef FLIGHTPROJECT_NUMBER_H
#define FLIGHTPROJECT_NUMBER_H


#include "Expression.h"

class Number: public Expression {
private:
    double m_value;
public:
    double calculate();
    double getValue(){
        return m_value;
    }
    Number(double value){
        m_value = value;
    }
};


#endif //FLIGHTPROJECT_NUMBER_H
