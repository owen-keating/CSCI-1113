//
//  main.cpp
//  lab11
//
//  Created by Hello on 4/14/21.
//

#include <iostream>
#include "Timer.hpp"
using namespace std;

//  warmup1

/*int main(){
    double *d_var;
    d_var = new double;
    double x = 0;
    *d_var = 10;
    cout << "Input: ";
    cin >> *d_var;
    cout << *d_var;
    double *d_array;
    d_array = new double[10];
    double arr[10];
    d_array = arr;
    for(int i = 0; i<10; i++){
        d_array[i] = 1.0;
    }
    cout << "x = " << x << endl;
    for(int i = 0; i<10; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    delete d_var;
    delete [] d_array;
}*/

//  warmup2

void foo(){
    int *arr = new int[100];
    /*for(int i = 0; i<100; i++){
        //do something
    }*/
    delete [] arr;
}

/*int main(){
    int a(1);
    int b(2);
    int *p1, *p2;
    p1 = &a;
    p2 = &b;
    *p1 = *p2;
    //a = b;
    *p2 = 10;
    cout << *p1 << ' ' << b << ' ' << a << endl;
}*/

//  warmup3

/*int main(){
    Timer *timePtr = new Timer;
    *timePtr = Timer(10,20);
    int *p;
    //p = timePtr.randArray(100);
    for(int i = 0; i<100; i++){
        cout << p[i] << " ";
    }
    delete [] p;
    delete timePtr;
}*/

//  stretch

double *momentum(double velocity[3], double mass){
    double *momentum = new double[3];
    for(int i = 0; i<3; i++){
        momentum[i] = mass * velocity[i];
    }
    return momentum;
}

/*int main(){
    double userMass;
    double userVelocity[3];
    double *userMomentum;
    cout << "Enter a mass: ";
    cin >> userMass;
    cout << "Enter velocity components: ";;
    for(int i = 0; i<3; i++){
        cin >> userVelocity[i];
    }
    userMomentum = momentum(userVelocity, userMass);
    cout << "<" << userVelocity[0] << ", " << userVelocity[1] << ", " << userVelocity[2] << "> * " << userMass;
    cout << " = <" << userMomentum[0] << ", " << userMomentum[1] << ", " << userMomentum[2] << ">" << endl;
}*/

//  workout1

double *randvec(){
    double *randvec = new double[3];
    //srand(int(time(0)));
    for(int i = 0; i<3; i++){
        randvec[i] = rand() % 200;
        randvec[i] += (rand() % 100)/100.0;
        if(randvec[i]>100){
            randvec[i] = (randvec[i] - 100) * (-1);
        }
    }
    return randvec;
}

/*int main(){
    srand(int(time(0)));
    double first[1000];
    double second[1000];
    double third[1000];
    for(int i = 0; i<1000; i++){
        double userMass = rand() % 9 + 1;
        userMass += (rand() % 100)/100.0;
        double *userVelocity;
        double *userMomentum;
        userVelocity = randvec();
        userMomentum = momentum(userVelocity, userMass);
        first[i] = userMomentum[0];
        second[i] = userMomentum[1];
        third[i] = userMomentum[2];
    }
    double average[3];
    int sum1 = 0;
    for(int i = 0; i<1000; i++){
        sum1+=first[i];
    }
    average[0] = sum1/1000.0;
    int sum2 = 0;
    for(int i = 0; i<1000; i++){
        sum2+=second[i];
    }
    average[1] = sum2/1000.0;
    int sum3 = 0;
    for(int i = 0; i<1000; i++){
        sum3+=third[i];
    }
    average[2] = sum3/1000.0;
    cout << "Average momentum: <" << average[0] << ", " << average[1] << ", " << average[2] << ">" << endl;
}*/

//  workout2

int *letterFrequency(string line){
    int *letters = new int[26];
    for(int i = 0; i<26; i++){
        letters[i] = 0;
    }
    char alpha[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char caps[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    for(int i = 0; i<line.length(); i++){
        char a = line[i];
        int x = -1;
        for(int j = 0; j<26; j++){
            if(a==alpha[j] or a==caps[j]){
                x = j;
            }
        }
        if(x>=0){
            letters[x]++;
        }
    }
    return letters;
}

int main(){
    string line;
    int *frequencies;
    cout << "Enter a string: ";
    getline(cin,line);
    frequencies = letterFrequency(line);
    cout << "Letter frequency" << endl;
    char alpha[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    for(int i = 0; i<26; i++){
        if(frequencies[i]>0){
            cout << alpha[i] << " " << frequencies[i] << endl;
        }
    }
}
