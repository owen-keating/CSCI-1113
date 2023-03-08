//
//  main.cpp
//  lab08
//
//  Created by Hello on 3/17/21.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//  warmup1

int timeToMinutes(int hours, int mins){
    return hours*60 + mins;
}

/*int main(){
    char a, c = 'y';
    int hours, mins, total;
    do{
        cout << "Enter a time duration (hh:mm) ";
        cin >> hours >> a >> mins;
        total = timeToMinutes(hours,mins);
        cout << "Total minutes: " << total << endl;
        cout << "Continue? (y/n): ";
        cin >> c;
        cout << endl;
    }while(c=='y');
}*/

//  warmup2

void minutesToTime(int minute_value, int& hours, int& mins){
    hours = minute_value/60;
    mins = minute_value%60;
}

/*int main(){
    char c = 'y';
    int minute_value = 0, hours = 0, mins = 0;
    do{
        cout << "Enter a number of minutes: ";
        cin >> minute_value;
        minutesToTime(minute_value, hours, mins);
        cout << "Hours:minutes is " << hours << ":";
        if(mins<10){
            cout << "0";
        }
        cout << mins << endl;
        cout << "Continue? (y/n): ";
        cin >> c;
        cout << endl;
    }while(c=='y');
}*/

//  stretch1

void elapsedTime(int h1, int m1, int h2, int m2, int& h, int& m){
    int minute_value = timeToMinutes(h2, m2) - timeToMinutes(h1, m1);
    minutesToTime(minute_value, h, m);
}

/*int main(){
    char a, b, c = 'y';
    int h1 = 0, m1 = 0, h2 = 0, m2 = 0, h = 0, m = 0;
    do{
        cout << "Enter first time (hours:minutes) ";
        cin >> h1 >> a >> m1;
        cout << "Enter second time (hours:minutes) ";
        cin >> h2 >> b >> m2;
        elapsedTime(h1, m1, h2, m2, h, m);
        if(h<0){
            h*=-1;
        }
        if(m<0){
            m*=-1;
        }
        cout << "Elapsed time is: " << h << ":";
        if(m<10){
            cout << "0";
        }
        cout << m << endl;
        cout << "Continue? (y/n): ";
        cin >> c;
        cout << endl;
    }while(c=='y');
}*/

//  stretch2

/*int main(){
    ofstream outFS;
    outFS.open("flightData.dat");
    if(!outFS.is_open()){
        cout << "Could not open file flightData.dat." << endl;
        return 1;
    }
    string a, b, c;
    cout << "Enter the flight number: ";
    cin >> a;
    while(a!="end"){
        outFS << a << " ";
        cout << "Enter the scheduled/actual arrival times: ";
        cin >> b >> c;
        outFS << b << " " << c << '\n';
        cout << endl << "Enter the flight number: ";
        cin >> a;
    }
    outFS.close();
    return 0;
}*/

//  stretch3

/*int main(){
    string s;
    cout << "Filename: ";
    getline(cin,s);
    ifstream inFS;
    inFS.open(s.c_str());
    if(!inFS.is_open()){
        cout << "Could not open file." << endl;
        return 1;
    }
    string numbers[10];
    string scheduled[10];
    string actual[10];
    int delays[10];
    for(int i = 0; i<10; i++){
        inFS >> numbers[i] >> scheduled[i] >> actual[i];
        int h = 0, m = 0;
        int n1 = int(scheduled[i].find(':'));
        int a = stoi(scheduled[i].substr(0,n1));
        int b = stoi(scheduled[i].substr(n1+1));
        int n2 = int(actual[i].find(':'));
        int c = stoi(actual[i].substr(0,n2));
        int d = stoi(actual[i].substr(n2+1));
        elapsedTime(a, b, c, d, h, m);
        delays[i] = timeToMinutes(h, m);
    }
    int sum = 0;
    for(int i = 0; i<10; i++){
        sum+=delays[i];
    }
    cout << "The average delay time was " << sum/10.0 << " minutes" << endl;
    int max = delays[0];
    int max_index = 0;
    for(int i = 0; i<10; i++){
        if(delays[i]>max){
            max = delays[i];
            max_index = i;
        }
    }
    cout << "The longest delay was " << max << " minutes on flight " << numbers[max_index] << endl;
    int min = delays[0];
    int min_index = 0;
    for(int i = 0; i<10; i++){
        if(delays[i]<min){
            min = delays[i];
            min_index = i;
        }
    }
    cout << "The shortest delay was " << min << " minutes on flight " << numbers[min_index] << endl;
    inFS.close();
    return 0;
}*/
