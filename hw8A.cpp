//
//  main.cpp
//  hw8A
//
//  Created by AMY KEATING on 4/23/21.
//

#include <iostream>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;


class GroceryList
{
public:
    GroceryList(){
        list = "";
    }
    void add(string item){
        list = list + item + " ";
    }
    string* checkout(int& size){
        string* receipt = new string[201];
        int num = 1;
        int end = 0;
        int index = 0;
        for(int i = 0; i<200; i++){
            if(index==list.length()){
                break;
            }
            else{
                int first = 0;
                int similar = 0;
                end = static_cast<int>(list.find(' ', index));
                for(int j = 0; j<num; j++){
                    int x = static_cast<int>(receipt[j].find(' '));
                    if(receipt[j].substr(x+1)==list.substr(index, end-index)){
                        if(similar==0){
                            first = j;
                        }
                        similar++;
                    }
                }
                if(similar==0){
                    receipt[i] = "1x " + list.substr(index, end-index);
                }
                else{
                    receipt[first] = to_string(similar+1) + "x " + list.substr(index, end-index);
                    receipt[i] = "-- " + list.substr(index, end-index);
                }
                index = end + 1;
                num++;
            }
        }
        size = num;
        int next = 0;
        bool check = true;
        for(int i = 0; i<num; i++){
            if(receipt[i].substr(0,2)=="--"){
                if(check==true){
                    check = false;
                }
                size--;
            }
            else{
                receipt[next] = receipt[i];
                check = true;
                next++;
            }
        }
        receipt[size-1] = "Total items: " + to_string(num-1);
        return receipt;
    }
private:
    string list;
};


int main()
{
    GroceryList gl;
    string item;
    getline(cin, item);
    while(item != "!checkout")
    {
        gl.add(item);
        getline(cin, item);
    }
    int size;
    string* receipt = gl.checkout(size); // this should initialize size
    cout << "\n\nReceipt:\n";
    int maxLen = 0;
    for(int i=0; i < size-1; i++) // list of items, but not total (last in array)
    {
        cout << receipt[i] << endl;
        if(static_cast<int>(receipt[i].length()) > maxLen)
        {
            maxLen = receipt[i].length();
        }
    }
    
    for(int i=0; i < maxLen; i++)
    {
        cout << "-";
    }
    cout << endl;
    cout << receipt[size-1] << endl; // total number of items
    delete [] receipt;
    return 0;
}
