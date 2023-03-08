//
//  Poly.hpp
//  lab10
//
//  Created by Hello on 4/12/21.
//

#ifndef POLY_H
#define POLY_H

#include <stdio.h>
using namespace std;

class Poly{
public:
    Poly();
    Poly(double f, double s, double t);
    double eval(double x);
    void roots(double& a, double& b, double& c, double& d);
    friend Poly operator+(Poly a, Poly b);
    friend ostream& operator<<(ostream& os, Poly a);
    friend istream& operator>>(istream& is, Poly& a);
private:
    double first;
    double second;
    double third;
};

#endif
