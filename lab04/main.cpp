//
//  main.cpp
//  lab04
//
//  Created by Hello on 2/17/21.
//

#include <iostream>
#include <math.h>
#include <string>
using namespace std;

//  1

/*int main(){
    string str1;
    cout << "Enter a word ";
    getline(cin,str1);
    for(int i = 0; i<str1.length(); i++){
        cout << str1.at(i) << endl;
    }
}*/

//  2

/*int main(){
    string str1, str2;
    cout << "Enter a word ";
    getline(cin,str1);
    for(int i = 0; i<str1.length()-1; i++){
        str2 = str2 + str1.at(i);
    }
    cout << str2 << endl;
}*/

//  3

/*int main(){
    string str1, str2;
    cout << "Enter a word: ";
    getline(cin,str1);
    str2 = str1.substr(0,str1.length()-1);
    cout << str2 << endl;
}*/

//  4

/*int main(){
    string str1, str2;
    cout << "Enter a word: ";
    getline(cin,str1);
    str2 = str1.substr(0,str1.find('='));
    cout << str2 << endl;
}*/

//  5
//  if no equal sign, find method returns '-1'

//  6

/*int main(){
    string str1, str2;
    cout << "Enter a word: ";
    getline(cin,str1);
    int x = int(str1.find(','));
    if(x==-1){
        cout << "no comma found" << endl;
    }
    else{
        cout << x << endl;
    }
}*/

//  warmup

/*int main(){

    string fullNames[2];
    double heights[2];
    
    for(int i = 0; i<2; i++){
        cout << "Please enter full name: ";
        getline(cin,fullNames[i]);
        cout << "Please enter " << fullNames[i] << "'s height: ";
        cin >> heights[i];
        cin.ignore(2,'\n');
        
    }
    
    cout << "If " << fullNames[0] << " and " << fullNames[1] << " stand on top of each other, their combined height will be " << (heights[0]+heights[1]) << endl;

}*/

//  stretch1

/*int main(){

    int num = 0;
    int total = 0;
    cout << "How many people? ";
    cin >> num;
    cin.ignore(1,'\n');
    string fullNames[num];
    double heights[num];
    
    for(int i = 0; i<num; i++){
        cout << "Please enter full name: ";
        getline(cin,fullNames[i]);
        cout << "Please enter " << fullNames[i] << "'s height: ";
        cin >> heights[i];
        cin.ignore(2,'\n');
        
    }
    
    for(int i = 0; i<num-1; i++){
        cout << fullNames[i] << " and ";
        total+=heights[i];
    }
    
    cout << fullNames[num-1];
    total+=heights[num-1];
    cout << " stand on top of each other, their combined height will be " << total << endl;
    
}*/

//  stretch2

/*int main(){

    int list[100];
    for(int i = 0; i<100; i++){
        list[i] = 100-i;
    }
    int n = 0;
    while(n==0){
        n=1;
        for(int j = 1; j<100; j++){
            if(list[j]<list[j-1]){
                int x = list[j-1];
                list[j-1] = list[j];
                list[j] = x;
                n=0;
            }
        }
    }
    for(int i = 0; i<20; i++){
        for(int j = 0; j<5; j++){
            cout << list[i*5+j] << " ";
        }
        cout << endl;
    }

}*/

//  stretch3

/*int main(){
    
    int count = 0;
    string somestring;
    cout << "Enter a string: ";
    getline(cin,somestring);
    for(int i = 0; i<somestring.length(); i++){
        if(somestring.at(i)==','){
            count++;
        }
    }
    cout << count << endl;

}*/

//  workout1

/*int main(){
 
    int count = 1;
    string somestring;
    cout << "Enter a string: ";
    getline(cin,somestring);
    for(int i = 0; i<somestring.length(); i++){
        if(somestring.at(i)==','){
            count++;
        }
    }
    string varray[count];
    int start = 0;
    int x = 0;
    for(int i = 0; i<somestring.length(); i++){
        if(somestring.at(i)==','){
            varray[x] = somestring.substr(start,i-start);
            x++;
            start = i+1;
        }
    }
    varray[x] = somestring.substr(start,somestring.length()-start);
    for(int i = 0; i<count; i++){
        cout << varray[i] << endl;
    }

}*/

//  workout2

/*int main(){

    string str;
    string newstr;
    cout << "Enter a string: ";
    getline(cin,str);
    for(int i = 0; i<str.length(); i++){
        if(str.at(i)!=' '){
            newstr = newstr + str.at(i);
        }
    }
    string palindrome = "Yes";
    for(int i = 0; i<=str.length()/2; i++){
        if(newstr.at(i)!=newstr.at(newstr.length()-i-1)){
            palindrome = "No";
        }
    }
    if(palindrome=="Yes"){
        cout << str << " is a palindrome." << endl;
    }
    else{
        cout << str << " is not a palindrome." << endl;
    }

}*/
