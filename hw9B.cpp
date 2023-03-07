//
//  main.cpp
//  hw9B
//
//  Created by Owen Keating on 4/30/21.
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
    gamePoints();
    gamePoints(const string names[], int s);
    void operator=(const gamePoints& p);
    ~gamePoints();
    int findPerson(const string& name) const;
    int getPoints(const string& name) const;
    void addPoints(const string& name, int toAdd);
    void showPoints() const;
    void changeName(string& name, string toChange);
    person winning() const;
private:
    person* players;
    int size;
};

gamePoints::gamePoints()
{
    players = new person[1];
    players[0] = person("", 0);;
    size = 1;
}

gamePoints::gamePoints(const string names[], int s)
{
    players = new person[s];
    for(int i = 0; i<s; i++){
        players[i] = person(names[i], 0);
    }
    size = s;
}

void gamePoints::operator=(const gamePoints& p)
{
    delete [] players;
    players = new person[p.size];
    for(int i = 0; i<p.size; i++){
        players[i] = person(p.players[i].getName(), p.players[i].getPoints());
    }
    size = p.size;
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
    for(int i = 0; i<size; i++){
        cout << players[i] << " ";
    }
    cout << endl;
}

void gamePoints::changeName(string& name, string toChange)
{
    int x = findPerson(name);
    players[x].setName(toChange);
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
    int games = 1;
    gamePoints* gms = new gamePoints[15];
    for(int i = 0; i<15; i++){
        gms[i] = gamePoints(arr, num);
    }
    delete [] arr;
    char c = 'x';
    while(c!='q'){
        cout << "Current: " << endl;
        for(int i = 0; i<games; i++){
            cout << "(Board " << i+1 << ") ";
            gms[i].showPoints();
        }
        cout << "Do you want to (a)dd points (what game, who and how much?), (c)hange a name on a board (old name to new name), see the current (w)inner on a board, (d)uplicate a board or (q)uit?" << endl;
        cin >> c;
        if(c=='a'){
            int gme = 0;
            string str = "";
            int update = 0;
            cin >> gme >> str >> update;
            gms[gme-1].addPoints(str, update);
        }
        if(c=='c'){
            int gam = 0;
            string stri = "";
            string nstr;
            cin >> gam >> stri >> nstr;
            gms[gam-1].changeName(stri, nstr);
        }
        if(c=='w'){
            int gm = 0;
            cin >> gm;
            cout << "Current winner is " << gms[gm-1].winning() << endl;
        }
        if(c=='d'){
            int du = 0;
            cin >> du;
            //gms[games] = gamePoints(gms[games-1]);
            gms[games] = gamePoints(gms[du-1]);
            games++;
        }
    }
    delete [] gms;
}
