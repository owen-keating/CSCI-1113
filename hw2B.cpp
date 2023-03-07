//
//  main.cpp
//  hw2B
//
//  Created by Hello on 2/12/21.
//

#include <iostream>
#include <math.h>
using namespace std;

int main(){
    
    int work_hours;
    int meeting_hours;
    char a, b, c, d;
    int work_minutes = 0;
    int meeting_minutes = 0;
    cin >> work_hours >> a;
    if(a=='h'){
        cin >> work_minutes >> b;
        work_minutes = work_minutes + work_hours * 60;
    }
    else{
        work_minutes = work_hours;
    }
    cin >> meeting_hours >> c;
    if(c=='h'){
        cin >> meeting_minutes >> d;
        meeting_minutes = meeting_minutes + meeting_hours * 60;
    }
    else{
        meeting_minutes = meeting_hours;
    }
    cout << (work_minutes - (work_minutes % meeting_minutes)) / meeting_minutes;
    
}
