//
//  main.cpp
//  hw6B
//
//  Created by Hello on 3/25/21.
//

#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 10000;

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

int days_until_birthday(int m1, int d1, int y1, int m2, int d2, int y2){
    int total = 0;
    if(y1==y2){
        for(int i = m1+1; i<m2; i++){
            total+=last_day(i,y1);
        }
        total+=d2;
        if(m1==m2){
            total-=d1;
        }
        else{
            total+=(last_day(m1,y1)-d1);
        }
    }
    else{
        for(int i = m1+1; i<13; i++){
            total+=last_day(i,y1);
        }
        total+=(last_day(m1,y1)-d1+d2);
        for(int i = 1; i<m2; i++){
            total+=last_day(i,y2);
        }
    }
    return total;
}

int main(){
    int month, day, year;
    char a, b;
    cout << "Current date?" << endl;
    cin >> month >> a >> day >> b >> year;
    ifstream inFS;
    inFS.open("birthdays.txt");
    if(!inFS.is_open()){
        cout << "No file detected!";
        return 1;
    }
    int size = 0;
    string people[MAX];
    while(!inFS.fail()){
        string a;
        getline(inFS,a);
        if(a!=""){
            people[size] = a;
            size++;
        }
    }
    inFS.close();
    string names[MAX];
    string birthdays[MAX];
    for(int i = 0; i<size; i++){
        int n = int(people[i].find(' '));
        names[i] = people[i].substr(0,n);
        birthdays[i] = people[i].substr(n+1);
    }
    int months[MAX];
    int days[MAX];
    int years[MAX];
    for(int i = 0; i<size; i++){
        int n1 = int(birthdays[i].find('/'));
        int n2 = int(birthdays[i].find('/', 2));
        months[i] = stoi(birthdays[i].substr(0,n1));
        days[i] = stoi(birthdays[i].substr(n1+1,n2));
        years[i] = stoi(birthdays[i].substr(n2+1));
    }
    int min_days = 1000;
    int num = 0;
    for(int i = 0; i<size; i++){
        int total_days = 0;
        if(month<months[i] or (month==months[i] and day<days[i])){
            total_days = days_until_birthday(month, day, year, months[i], days[i], year);
        }
        else{
            total_days = days_until_birthday(month, day, year, months[i], days[i], year+1);
        }
        if(total_days<min_days){
            min_days = total_days;
            num = i;
        }
    }
    for(int i = 0; i<size; i++){
        cout << years[i] << endl;
    }
    int age = 0;
    if(month<months[num] or (month==months[num] and day<days[num])){
        age = year - years[num];
    }
    else{
        age = year + 1 - years[num];
    }
    cout << "Next birthday:" << endl << names[num] << endl;
    cout << "in " << min_days << " days" << endl;
    cout << "will turn " << age;
    return 0;
}

/*int main(){
    ofstream outFS;
    outFS.open("birthdays.txt");
    outFS << "Nick_Florin 11/7/2000" << endl;
    outFS << "David_Woodhouse 8/12/2020" << endl;
    outFS << "Michael_Smith 11/13/1949" << endl;
    outFS << "Mary_Rasmussen 1/13/1987" << endl;
    outFS << "Martin_Hughes 3/13/1976" << endl;
    outFS << "Melanie_Mouzon 5/15/1933" << endl;
    outFS << "Christine_Bonin 2/10/1945" << endl;
    outFS << "William_Holland 6/13/1999" << endl;
    outFS << "Doyle_Dye 6/14/2014" << endl;
    outFS << "Steve_Burkey_Frazier 3/13/2004" << endl;
    outFS << "Nell_Granberry 4/25/1979" << endl;
    outFS << "Madeleine_Daniel 7/9/1968" << endl;
    outFS << "Lillie_Callender 6/16/2015" << endl;
    outFS << "Shoshana_Falls 5/27/2019" << endl;
    outFS.close();
    return 0;
}*/
