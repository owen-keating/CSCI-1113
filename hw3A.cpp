//
//  main.cpp
//  hw3A
//
//  Created by Owen Keating on 2/19/21.
//

#include <iostream>
#include <math.h>
using namespace std;

int main(){
    
    double investment, rate, withdrawal, balance;
    double total_withdrawn = 0.0;
    int years = 0;
    cout << "Initial investment? ";
    cin >> investment;
    cout << "Yearly growth rate? ";
    cin >> rate;
    cout << "Yearly withdraw amount? ";
    cin >> withdrawal;
    cout << "Desired balance? " << endl;
    cin >> balance;
    while(investment<=balance){
        years++;
        investment = investment * (1 + rate);
        if(withdrawal>=investment){
            total_withdrawn+=investment;
            investment = 0;
            break;
        }
        else{
            total_withdrawn = total_withdrawn + withdrawal;
            investment-=withdrawal;
        }
    }
    cout << "Years: " << years << endl;
    cout << "Balance at end: " << investment << endl;
    cout << "Amount withdrawn over period: " << total_withdrawn << endl;
    
}
