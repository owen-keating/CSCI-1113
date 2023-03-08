//
//  main.cpp
//  lab02
//
//  Created by Hello on 2/3/21.
//

#include <iostream>
#include <math.h>
using namespace std;

//  warmup

/*int main(){
    
    double L;
    cout << "Value for L?" << endl;
    cin >> L;
    double v;
    cout << "Value for v?" << endl;
    cin >> v;
    double c = 3.0e10;
    double LR = L * sqrt((1-(v*v)/(c*c)));
    cout << LR << endl << endl;
    
}*/

//  stretch1

/*int main(){
 
    int weight;
    cout << "Weight in pounds?" << endl;
    cin >> weight;
    int height;
    cout << "Height in inches?" << endl;
    cin >> height;
    int age;
    cout << "Age in years?" << endl;
    cin >> age;
    char gender;
    cout << "Gender? 'M' for male, 'F' for female" << endl;
    cin >> gender;
    double calories;
    double bars;
    if(gender=='M'){
        calories = 66 + (6.3*weight) + (12.9*height) - (6.8*age);
    }
    else{
        calories = 655 + (4.3*weight) + (4.7*height) - (4.7*age);
    }
    bars = calories / 230;
    cout << "Number of calories: " << calories << endl;
    cout << "Number of chocolate bars " << bars << endl << endl;
    
}*/

//  stretch2

/*int main(){
    
    double temp;
    cout << "Enter the temperature: ";
    cin >> temp;
    char type;
    cout << "Enter Celsius (c) or Fahrenheit (f): ";
    cin >> type;
    if(type=='c'){
        temp = (temp*9/5) + 32;
        cout << "The temperature in Fahrenheit is " << temp << endl << endl;
    }
    else{
        temp = (temp-32) * 5/9;
        cout << "The temperature in Celsius is " << temp << endl << endl;
    }
    
}*/

//  stretch3

/*int main(){
    
    int first;
    char sign;
    int second;
    cout << "Enter an equation: ";
    cin >> first >> sign >> second;
    
    switch(sign){
        case '+':
            cout << first + second << endl << endl;
            break;
        case '-':
            cout << first - second << endl << endl;
            break;
        case '*':
            cout << first * second << endl << endl;
            break;
        case '/':
            cout << first / second << endl << endl;
            break;
        default:
            cout << "Error. Incorrect operator." << endl << endl;
            break;
    }
    
}*/

//  workout

int main(){
    int dependents;
    double hours, pay, withheld;
    cout << "Hours worked? ";
    cin >> hours;
    cout << "Number of dependents? ";
    cin >> dependents;
    if(hours>40){
        pay = 671.2 + 25.17 * (hours-40);
    }
    else{
        pay = 16.78 * hours;
    }
    cout << "Total pay: $" << pay << endl;
    if(dependents>=3){
        withheld = 35;
        cout << "$35 withheld for health insurance." << endl;
    }
    else{
        withheld = 0;
    }
    cout << "$" << pay*0.06 << " withheld for social security." << endl;
    withheld+=pay*0.06;
    cout << "$" << pay*0.14 << " withheld for federal income tax." << endl;
    withheld+=pay*0.14;
    cout << "$" << pay*0.05 << " withheld for state income tax." << endl;
    withheld+=pay*0.05;
    cout << "$10 withheld for union dues." << endl;
    withheld+=10;
    cout << "$" << pay - withheld << " net take-home pay." << endl << endl;
}
