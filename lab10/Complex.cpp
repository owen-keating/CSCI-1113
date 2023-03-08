//
//  Complex.cpp
//  lab10
//
//  Created by Hello on 4/12/21.
//

#include <iostream>
#include "Complex.hpp"
using namespace std;

Complex::Complex(){
    real = 0.0;
    imag = 0.0;
}

Complex::Complex(double r, double i){
    real = r;
    imag = i;
}

Complex operator+(Complex a, Complex b){
    Complex totalval;
    totalval.real = a.real + b.real;
    totalval.imag = a.imag + b.imag;
    return totalval;
}

Complex operator-(Complex a){
    Complex negval;
    negval.real = a.real*-1;
    negval.imag = a.imag*-1;
    return negval;
}

ostream& operator<<(ostream& os, Complex a){
    //os << a.real;
    if(a.real==0){
        os << 0;
    }
    else{
        os << a.real;
    }
    if(a.imag<0){
        os << " - " << a.imag*(-1) << 'i';
    }
    else{
        os << " + " << a.imag <<  'i';
    }
    return os;
}

void Complex::set_real(double r){
    real = r;
}

void Complex::set_imag(double i){
    imag = i;
}
