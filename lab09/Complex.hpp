//
//  Complex.hpp
//  lab09
//
//  Created by Hello on 3/30/21.
//

#ifndef COMPLEX_H
#define COMPLEX_H

class Complex{
public:
    Complex();
    Complex(double,double);
    void output() const;
    double getReal() const;
    double getImag() const;
    void setReal(double r);
    void setImag(double i);
private:
    double real;
    double imag;
};

#endif
