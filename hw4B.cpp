//
//  main.cpp
//  hw4B
//
//  Created by Owen Keating on 3/11/21.
//

#include <iostream>
using namespace std;

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

int main(){
    int month, day, year;
    char a, b;
    cout << "Enter start date (no spaces):" << endl;
    cin >> month >> a >> day >> b >> year;
    int end_month, end_day, end_year;
    char c, d;
    cout << "Enter end date (no spaces):" << endl;
    cin >> end_month >> c >> end_day >> d >> end_year;
    int total_days = 0;
    if(year>end_year){
        total_days = -1;
    }
    else if(year==end_year){
        if(month>end_month){
            total_days = -1;
        }
        else if(month==end_month){
            if(day>end_day){
                total_days = -1;
            }
            else if(day==end_day){
                total_days = 0;
            }
            else{
                total_days = end_day - day;
            }
        }
        else{
            for(int i = month+1; i<end_month; i++){
                total_days += last_day(i,year);
            }
            total_days += (last_day(month,year) - day + end_day);
        }
    }
    else{
        for(int i = year+1; i<end_year; i++){
            if(isLeapYear(i)==true){
                total_days += 366;
            }
            else{
                total_days += 365;
            }
        }
        for(int i = month+1; i<13; i++){
            total_days += last_day(i,year);
        }
        total_days += (last_day(month,year) - day + end_day);
        for(int i = 1; i<end_month; i++){
            total_days += last_day(i,end_year);
        }
    }
    if(total_days==-1){
        cout << "Never...";
    }
    else if(total_days==1){
        cout << "You have to wait 1 day";
    }
    else{
        cout << "You have to wait " << total_days << " days";
    }
    return 0;
}
