//
//  main.cpp
//  lab07
//
//  Created by Hello on 3/10/21.
//

#include <iostream>
using namespace std;

//  warmup1

void reverseNum(int n){
    if(n<10){
        cout << n;
    }
    else{
        cout << n % 10;
        reverseNum(n/10);
    }
}

/*int main(){
    int n;
    cout << "Enter an integer value: ";
    cin >> n;
    cout << "Reverse number: ";
    reverseNum(n);
    cout << endl;
}*/

//  warmup2

int maxValue(int vals[], int size, int start){
    if(size==1){
        return vals[0];
    }
    else{
        if(vals[start]>vals[0]){
            vals[0] = vals[start];
        }
        return maxValue(vals, size-1, start+1);
    }
}

/*int main(){
    int max, size;
    cout << "How many values: ";
    cin >> size;
    int vals[size];
    cout << "Enter values: ";
    for(int i = 0; i<size; i++){
        cin >> vals[i];
    }
    max = maxValue(vals, size, 1);
    cout << "Maximum value: " << max << endl;
}*/

//  stretch

int factorial(int n){
    if(n==1){
        return 1;
    }
    else{
        return n * factorial(n-1);
    }
}

/*int main(){
    int n;
    cout << "Enter an integer value: ";
    cin >> n;
    int fact = factorial(n);
    cout << n << " factorial is " << fact << endl;
}*/

//  workout1

int choose(int n, int k){
    if(k==n or k==0){
        return 1;
    }
    else{
        return choose(n-1,k-1) + choose(n-1,k);
    }
}

/*int main(){
    int n, k;
    cout << "Enter the amount of things: ";
    cin >> n;
    cout << "Enter the size of one combination: ";
    cin >> k;
    int bin = choose(n,k);
    cout << bin << " combinations can be made " << endl;
}*/

//  workout2

int gcd(int a, int b){
    if(b==0){
        return a;
    }
    else{
        return gcd(b,a%b);
    }
}

/*int main(){
    int a, b;
    cout << "Enter two integer values: ";
    cin >> a >> b;
    int great = gcd(a,b);
    cout << "Greatest common divisor: " << great << endl;
}*/
