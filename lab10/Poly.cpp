//
//  Poly.cpp
//  lab10
//
//  Created by Hello on 4/12/21.
//

#include <iostream>
#include "Poly.hpp"
using namespace std;

Poly::Poly(){
    first = 0.0;
    second = 0.0;
    third = 0.0;
}

Poly::Poly(double f, double s, double t){
    first = f;
    second = s;
    third = t;
}

Poly operator+(Poly a, Poly b){
    Poly sum;
    sum.first = a.first + b.first;
    sum.second = a.second + b.second;
    sum.third = a.third + b.third;
    return sum;
}

ostream& operator<<(ostream& os, Poly a){
    if(a.first==0 and a.second==0){
        os << a.third;
    }
    else if(a.second==0){
        os << a.first << "x^2";
        if(a.third<0){
            os << " - " << -a.third;
        }
        else{
            os << " + " << a.third;
        }
    }
    else if(a.first==0){
        os << a.second << "x";
        if(a.third<0){
            os << " - " << -a.third;
        }
        else{
            os << " + " << a.third;
        }
    }
    else{
        os << a.first << "x^2";
        if(a.second<0){
            os << " - " << -a.second << "x";
        }
        else{
            os << " + " << a.second << "x";
        }
        if(a.third<0){
            os << " - " << -a.third;
        }
        else{
            os << " + " << a.third;
        }
    }
    return os;
}

istream& operator>>(istream& is, Poly& a){
    char c, d, e, f;
    is >> c >> a.first >> d >> a.second >> e >> a.third >> f;
    return is;
}

double Poly::eval(double x){
    return first*x*x + second*x + third;
}

void Poly::roots(double& a, double& b, double& c, double& d){
    double discriminant = (second*second) - (4*first*third);
    if(discriminant>0){
        a = ((-second) + sqrt(discriminant))/(2*first);
        c = ((-second) - sqrt(discriminant))/(2*first);
    }
    else{
        a = (-second)/(2*first);
        c = a;
    }
    if(discriminant<0){
        b = sqrt(4*first*third - second*second)/(2*first);
        d = -b;
    }
}
