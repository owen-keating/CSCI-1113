//
//  main.cpp
//  hw9A
//
//  Created by Owen Keating on 4/29/21.
//

#include <iostream>

using namespace std;

class person{
public:
    person();
    person(const string& n, int s);
    int getPoints() const;
    string getName() const;
    void setPoitns(int p);
    void setName(string n);
private:
    string name;
    int score;
};

person::person()
{
    name = "";
    score = 0;
}

person::person(const string& n, int s)
{
    name = n;
    score = s;
}

int person::getPoints() const
{
    return score;
}

string person::getName() const
{
    return name;
}

void person::setPoitns(int p)
{
    score = p;
}

void person::setName(string n)
{
    name = n;
}

ostream& operator<<(ostream& out, person p)
{
    out << p.getName() << ":" << p.getPoints();
    return out;
}

class gamePoints{
public:
    gamePoints(const string names[], int s);
    ~gamePoints();
    int findPerson(const string& name) const;
    int getPoints(const string& name) const;
    void addPoints(const string& name, int toAdd);
    void showPoints() const;
    person winning() const;
private:
    person* players;
    int size;
};

gamePoints::gamePoints(const string names[], int s)
{
    players = new person[s];
    for(int i = 0; i<s; i++){
        players[i] = person(names[i], 0);
    }
    size = s;
}

gamePoints::~gamePoints()
{
    delete [] players;
}

int gamePoints::findPerson(const string& name) const
{
    for(int i = 0; i<size; i++){
        string s = players[i].getName();
        if(s==name){
            return i;
        }
    }
    return -1;
}

int gamePoints::getPoints(const string& name) const
{
    int x = findPerson(name);
    return players[x].getPoints();
    
}

void gamePoints::addPoints(const string& name, int toAdd)
{
    int x = findPerson(name);
    players[x].setPoitns(getPoints(name)+toAdd);
}

void gamePoints::showPoints() const
{
    cout << "Current points:" << endl;
    for(int i = 0; i<size; i++){
        cout << players[i] << " ";
    }
    cout << endl;
}

person gamePoints::winning() const
{
    int index = 0;
    int max = 0;
    for(int i = 0; i<size; i++){
        if(players[i].getPoints()>max){
            index = i;
            max = players[i].getPoints();
        }
    }
    return players[index];
}

int main(){
    int num = 0;
    cout << "How many players?" << endl;
    cin >> num;
    string* arr = new string[num];
    cout << "Enter the names (single words):" << endl;
    for(int i = 0; i<num; i++){
        cin >> arr[i];
    }
    gamePoints g1 = gamePoints(arr, num);
    delete [] arr;
    char c = 'x';
    while(c!='q'){
        g1.showPoints();
        cout << "Do you want to (a)dd points (if so to who and how much?), see the current (w)inner or (q)uit?" << endl;
        cin >> c;
        if(c=='a'){
            string str = "";
            int update = 0;
            cin >> str >> update;
            g1.addPoints(str, update);
        }
        if(c=='w'){
            cout << "Current winner is " << g1.winning() << endl;
        }
    }
}
