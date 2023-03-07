//
//  main.cpp
//  hw3A
//
//  Created by Owen Keating on 2/26/21.
//

#include <iostream>
#include <math.h>
#include <vector>
#include <string>
using namespace std;


int main(){
    
    char a, b;
    int month, day, year;
    int count = 2;
    cout << "Gimme dates!" << endl;
    cin >> month >> a >> day >> b >> year;
    vector<int> months(1);
    months.at(0) = month;
    vector<int> days(1);
    days.at(0) = day;
    while(month!=-1){
        cin >> month;
        if(month!=-1){
            cin >> a >> day >> b >> year;
            months.resize(count);
            days.resize(count);
            months.at(count-1) = month;
            days.at(count-1) = day;
            count++;
        }
    }
    int mcount = 0;
    int max_month = months.at(0);
    for(int i = 0; i<months.size(); i++){
        int n = 0;
        for(int j = 0; j<months.size(); j++){
            if(months.at(j)==months.at(i)){
                n++;
            }
        }
        if(n>mcount){
            mcount = n;
            max_month = months.at(i);
        }
    }
    int dcount = 0;
    int max_day = days.at(0);
    for(int i = 0; i<days.size(); i++){
        int n = 0;
        for(int j = 0; j<days.size(); j++){
            if(days.at(j)==days.at(i)){
                n++;
            }
        }
        if(n>dcount){
            dcount = n;
            max_day = days.at(i);
        }
    }
    
    cout << "Most common day: " << endl << max_day << endl;
    cout << "Most common birth month: " << endl << max_month;
    
}
