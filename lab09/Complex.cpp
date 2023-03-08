//
//  Complex.cpp
//  lab09
//
//  Created by Hello on 3/30/21.
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

void Complex::output() const{
    cout << real << " + " << imag << "i" << endl;
}

double Complex::getReal() const{
    return real;
}

double Complex::getImag() const{
    return imag;
}

void Complex::setReal(double r){
    real = r;
}

void Complex::setImag(double i){
    imag = i;
}
