//
//  Complex.hpp
//  lab10
//
//  Created by Hello on 4/12/21.
//

#ifndef COMPLEX_H
#define COMPLEX_H

#include <stdio.h>
using namespace std;

class Complex{
public:
    Complex();
    Complex(double r, double i);
    void set_real(double r);
    void set_imag(double i);
    friend Complex operator+(Complex a, Complex b);
    friend Complex operator-(Complex a);
    friend ostream& operator<<(ostream& os, Complex a);
    //friend istream& operator>>(istream& is, Complex& a);
    //double real;
    //double imag;
private:
    double real;
    double imag;
};

#endif
