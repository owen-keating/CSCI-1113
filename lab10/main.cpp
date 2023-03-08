//
//  main.cpp
//  lab10
//
//  Created by Hello on 3/31/21.
//

#include <iostream>
#include "Point.hpp"
#include "Complex.hpp"
#include "Poly.hpp"
using namespace std;

//  warmup

/*int main(){
    Point p1 = Point(3,5);
    Point p2 = Point(2,6);
    Point totalval = p1 + p2;
    cout << totalval;
    return 0;
}*/

//  stretch

/*int main(){
    Complex c1, c2, c3;
    c1 = Complex(3.0,-2.0);
    c2 = Complex(-5.4,-6.5);
    c3 = c1 + c2;
    cout << "The sum is: " << c3 << endl;
    cout << "and negating the sum yields: " << -c3 << endl;
    return 0;
}*/

//  workout1

/*int main(){
    Poly q1, q2, sum;
    q1 = Poly(3, 4, -2);
    q2 = Poly(0, -4, 10);
    sum = q1 + q2;
    cout << "q1: " << q1 << endl;
    cout << "q2: " << q2 << endl;
    cout << "sum: " << sum << endl;
    return 0;
}*/

//  workout2

/*int main(){
    Poly inpoly;
    cout << "Input a quadratic polynomial: ";
    cin >> inpoly;
    for(int i = 0; i<=10; i++){
        cout << "f(" << i << ") is: " << inpoly.eval(i) << endl;
    }
    Complex c1, c2;
    double a, b, c, d;
    inpoly.roots(a, b, c, d);
    c1.set_real(a);
    c1.set_imag(b);
    c2.set_real(c);
    c2.set_imag(d);
    cout << "The roots of f(x) are " << c1 << "\t" << c2 << endl;
}*/
