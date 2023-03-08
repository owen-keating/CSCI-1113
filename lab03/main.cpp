//
//  main.cpp
//  lab03
//
//  Created by Hello on 2/10/21.
//

#include <iostream>
#include <math.h>
using namespace std;

//  warmup1

/*int main(){
 
    int first = 0;
    int second = 1;
    int count;
    int sum = 0;
    cout << "How many Fibonacci numbers? ";
    cin >> count;
    cout << "0 ";
    cout << "1 ";
    while(count > 0){
        sum = first + second;
        cout << sum << " ";
        first = second;
        second = sum;
        count--;
    }
    cout << endl;

}*/

//  warmup2

/*int main(){
    
    int total = 0;
    for(int i=1;i<100;i++){
        total+=i;
    }
    cout << total << endl;
    
}*/

//  warmup3

/*int main(){
    
    for(int i=1;i<=10;i++){
        for(int j=1;j<=10;j++){
            cout << i*j << " ";
        }
        cout << endl;
    }
    
}*/

//  stretch

/*int main(){
    
    int num;
    cout << "Number to take square root of: ";
    cin >> num;
    double old_guess;
    double new_guess = num/2;
    double answer = sqrt(num);
    do{
        cout << new_guess << endl;
        old_guess = new_guess;
        new_guess = (old_guess + num/old_guess)/2;
    }while(abs((new_guess-old_guess)/old_guess)>0.01);
    cout << "Babylonian value: " << new_guess << endl;
    cout << "Actual value: " << answer << endl;
    
}*/

//  workout1

/*int main(){
    
    double init_temp;
    cout << "Enter the initial temperature: ";
    cin >> init_temp;
    double surr_temp;
    cout << "Enter the temperature of the surroundings: ";
    cin >> surr_temp;
    double rate;
    cout << "Enter the growth (decay) rate: ";
    cin >> rate;
    double step;
    cout << "Enter the time step in hours: ";
    cin >> step;
    int hours;
    cout << "Enter the simulation length in hours: ";
    cin >> hours;
    
    //int count = hours/step;
    //cout << count;
    double new_temp;
    int i = 1;
    while(i<=hours/step){
        double t = i*step;
        cout << t << "  ";
        new_temp = init_temp + rate * (surr_temp - init_temp) * step;
        cout << new_temp << endl;
        init_temp = new_temp;
        i+=1;
    }
    
}*/

//  workout2

/*int main(){
    
    int num;
    cout << "Enter an integer value from 1 to 999: ";
    cin >> num;
    
    int ones = num % 10;
    cout << ones << endl;
    int tens = (num % 100 - ones)/10;
    cout << tens << endl;
    int hundreds = (num % 1000 - (tens*10+ones))/100;
    cout << hundreds << endl;
    
    if(hundreds==9){
        cout << "CM";
    }
    else if(hundreds>=5){
        cout << "D";
        for(int i=hundreds-5;i>0;i--){
            cout << "C";
        }
    }
    else if(hundreds==4){
        cout << "CD";
    }
    else{
        for(int i=hundreds;i>0;i--){
            cout << "C";
        }
    }
    
    if(tens==9){
        cout << "XC";
    }
    else if(tens>=5){
        cout << "L";
        for(int i=tens-5;i>0;i--){
            cout << "X";
        }
    }
    else if(tens==4){
        cout << "XL";
    }
    else{
        for(int i=tens;i>0;i--){
            cout << "X";
        }
    }
    
    if(ones==9){
        cout << "IX";
    }
    else if(ones>=5){
        cout << "V";
        for(int i=ones-5;i>0;i--){
            cout << "I";
        }
    }
    else if(ones==4){
        cout << "IV";
    }
    else{
        for(int i=ones;i>0;i--){
            cout << "I";
        }
    }
    cout << endl;
    
}*/
