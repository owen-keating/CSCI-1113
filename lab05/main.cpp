//
//  main.cpp
//  lab05
//
//  Created by Hello on 2/24/21.
//

#include <iostream>
#include <math.h>
using namespace std;

//  warmup

void two_dimensional_array(){
    int array[3][3];
    int x = 10;
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            array[i][j] = x;
            x--;
        }
    }
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

double babylonianRoot(double num){
    double old_guess;
    double new_guess = num/2;
    do{
        old_guess = new_guess;
        new_guess = (old_guess + num/old_guess)/2;
    }while(abs((new_guess-old_guess)/old_guess)>0.01);
    return new_guess;
}

/*int main(){
    //two_dimensional_array();
    int num = 0;
    char c = 'y';
    while(c=='y'){
        cout << "enter a value: ";
        cin >> num;
        double square = babylonianRoot(num);
        cout << "square root of " << num << " is " << square << endl;
        cout << "continue? (y/n): ";
        cin >> c;
        cout << endl;
    }
    return 0;
}*/

//  stretch

double exponential(double old_guess, int n){
    double y = 1;
    for(int i = 0; i<n; i++){
        y*=old_guess;
    }
    return y;
}

double rootN(double x, int n){
    double old_guess;
    double new_guess = x/2;
    do{
        old_guess = new_guess;
        double y = exponential(old_guess, n-1);
        new_guess = ((n-1)*old_guess + x/y)/n;
    }while(abs((new_guess-old_guess)/old_guess)>0.01);
    return new_guess;
}

/*int main(){
    double x = 0.0;
    int n = 0;
    char c = 'y';
    while(c=='y'){
        cout << "enter a value and root: ";
        cin >> x >> n;
        double root = rootN(x, n);
        cout << "the root is: " << root << endl;
        cout << "continue? (y/n): ";
        cin >> c;
        cout << endl;
    }
    return 0;
}*/

//  workout

const int NROWS = 20;
const int NCOLS = 20;

void display(double temp[][NCOLS]){
    for(int i = 0; i<NROWS; i++){
        for(int j = 0; j<NCOLS; j++){
            cout << temp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    double top, bottom, left, right, internal;
    double temp[NROWS][NCOLS];
    double old[NROWS][NCOLS];
    cout << "Top temperature: ";
    cin >> top;
    cout << "Bottom temperature: ";
    cin >> bottom;
    cout << "Left temperature: ";
    cin >> left;
    cout << "Right temperature: ";
    cin >> right;
    cout << "Internal temperature: ";
    cin >> internal;
    for(int i = 0; i<NROWS; i++){
        for(int j = 0; j<NCOLS; j++){
            if(i==0){
                temp[i][j] = top;
            }
            else if(i==NROWS-1){
                temp[i][j] = bottom;
            }
            else if(j==0){
                temp[i][j] = left;
            }
            else if(j==NCOLS-1){
                temp[i][j] = right;
            }
            else{
                temp[i][j] = internal;
            }
        }
    }
    bool steady = true;
    double convergence_criterion = 0.001;
    do{
        steady = true;
        for(int i = 0; i<NROWS; i++){
            for(int j = 0; j<NCOLS; j++){
                old[i][j] = temp[i][j];
            }
        }
        for(int i = 0; i<NROWS; i++){
            for(int j = 0; j<NCOLS; j++){
                if(i!=0 and i!=NROWS-1 and j!=0 and j!=NCOLS-1){
                    temp[i][j] = 0.25*(old[i][j-1]+old[i][j+1]+old[i-1][j]+old[i+1][j]);
                    if(abs(temp[i][j]-old[i][j])>convergence_criterion){
                        steady = false;
                    }
                }
            }
        }
        display(temp);
    }while(steady==false);
}
