//
//  main.cpp
//  lab06
//
//  Created by Hello on 3/3/21.
//

#include <iostream>
using namespace std;

//  warmup1

const int SIZE = 100;

void display(int size, int array[][SIZE]){
    for(int i = 0; i<size; i++){
        for(int j = 0; j<size; j++){
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
    
}

void identity(int size, int array[][SIZE]){
    int new_array[SIZE][SIZE];
    for(int i = 0; i<size; i++){
        for(int j = 0; j<size; j++){
            new_array[i][j] = array[i][j];
        }
    }
    display(size, new_array);
}

/*int main(){
    int size;
    cout << "What size matrix? ";
    cin >> size;
    int array[SIZE][SIZE];
    for(int i = 0; i<size; i++){
        for(int j = 0; j<size; j++){
            if(i==j){
                array[i][j] = 1;
            }
            else{
                array[i][j] = 0;
            }
        }
    }
    identity(size, array);
}*/

//  warmup2

bool isLeapYear(int year){
    bool leap = false;
    if(year%100==0){
        if(year%400==0){
            leap = true;
        }
    }
    else if(year%4==0){
        leap = true;
    }
    return leap;
}

/*int main(){
    int year;
    char c = 'y';
    do{
        cout << "enter a year value: ";
        cin >> year;
        bool leap = isLeapYear(year);
        if(leap==true){
            cout << year << " is a leap year" << endl;
        }
        else{
            cout << year << " is not a leap year" << endl;
        }
        cout << "continue?(y/n): ";
        cin >> c;
        cout << endl;
    }while(c=='y');
}*/

//  stretch1

int last_day(int month, int year){
    bool leap = isLeapYear(year);
    if(month==2){
        if(leap==false){
            return 28;
        }
        else{
            return 29;
        }
    }
    else if(month==4 or month==6 or month==9 or month==11){
        return 30;
    }
    else{
        return 31;
    }
}

/*int main(){
    int month, year;
    char c = 'y';
    do{
        cout << "enter a month and year: ";
        cin >> month >> year;
        int days = last_day(month, year);
        cout << "days in month: " << days << endl;
        cout << "continue?(y/n): ";
        cin >> c;
        cout << endl;
    }while(c=='y');
}*/

//  stretch2

/*int main(){
    int day, month, year;
    char c = 'y';
    do{
        cout << "enter a date as mm dd yyyy: ";
        cin >> month >> day >> year;
        int days = last_day(month, year);
        if(days==day){
            day = 1;
            if(month==12){
                month = 1;
                year++;
            }
            else{
                month++;
            }
        }
        else{
            day++;
        }
        cout << "next day is: " << month << " " << day << " " << year << endl;
        cout << "continue?(y/n): ";
        cin >> c;
        cout << endl;
    }while(c=='y');
}*/

//  workout

int main(){
    int a1, a2, a3, b1, b2, b3, c1, c2, c3;
    cout << "Input first matrix:" << endl;
    cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3 >> c1 >> c2 >> c3;
    int d1, d2, d3, e1, e2, e3, f1, f2, f3;
    cout << "Input second matrix:" << endl;
    cin >> d1 >> d2 >> d3 >> e1 >> e2 >> e3 >> f1 >> f2 >> f3;
    int g1, g2, g3, h1, h2, h3, i1, i2, i3;
    cout << "Output matrix:" << endl;
    g1 = (a1*d1) + (a2*e1) + (a3*f1);
    g2 = (a1*d2) + (a2*e2) + (a3*f2);
    g3 = (a1*d3) + (a2*e3) + (a3*f3);
    h1 = (b1*d1) + (b2*e1) + (b3*f1);
    h2 = (b1*d2) + (b2*e2) + (b3*f2);
    h3 = (b1*d3) + (b2*e3) + (b3*f3);
    i1 = (c1*d1) + (c2*e1) + (c3*f1);
    i2 = (c1*d2) + (c2*e2) + (c3*f2);
    i3 = (c1*d3) + (c2*e3) + (c3*f3);
    cout << g1 << " " << g2 << " " << g3 << endl;
    cout << h1 << " " << h2 << " " << h3 << endl;
    cout << i1 << " " << i2 << " " << i3 << endl;
}
