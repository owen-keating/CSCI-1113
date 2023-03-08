//
//  main.cpp
//  lab13
//
//  Created by Hello on 4/28/21.
//

#include <iostream>
#include <cctype>
using namespace std;

class sport {
protected:
    double area;
    int numPlayers;
    int perScore;
public:
    virtual void displayInfo();
};

class timed_sport : public sport {
protected:
    double duration;
};

class football : public timed_sport {
private:
    int downs;
public:
    football();
    void displayInfo();
};

class soccer : public timed_sport {
private:
    int numSubs;
public:
    soccer();
    void displayInfo();
};

class net_sport : public sport {
protected:
    int perSet;
    double netHeight;
};

class tennis : public net_sport {
private:
    int numMatches;
public:
    tennis();
    void displayInfo();
};

class volleyball : public net_sport {
public:
    volleyball();
    void displayInfo();
};

football::football()
{
    area = 5351.2;
    duration = 60;
    numPlayers = 11;
    perScore = 7;
    downs = 4;
}

soccer::soccer()
{
    area = 7000;
    duration = 90;
    numPlayers = 11;
    perScore = 1;
    numSubs = 3;
}

tennis::tennis()
{
    string str;
    cout << "Singles or doubles? ";
    cin >> str;
    if(tolower(str[0])=='s'){
        area = 195;
        numPlayers = 1;
    }
    else{
        area = 260;
        numPlayers = 2;
    }
    numMatches = 3;
    perScore = 1;
    perSet = 6;
    netHeight = 0.914;
}

volleyball::volleyball()
{
    area = 162;
    numPlayers = 6;
    perScore = 1;
    perSet = 15;
    netHeight = 2.43;
}

void sport::displayInfo(){}

void football::displayInfo()
{
    cout << "Area played in: " << area << endl;
    cout << "Number of players: " << numPlayers << endl;
    cout << "Points per score: " << perScore << endl;
    cout << "Duration: " << duration << endl;
    cout << "Downs: " << downs << endl;
}

void soccer::displayInfo()
{
    cout << "Area played in: " << area << endl;
    cout << "Number of players: " << numPlayers << endl;
    cout << "Points per score: " << perScore << endl;
    cout << "Duration: " << duration << endl;
    cout << "Number of substitutions: " << numSubs << endl;
}

void tennis::displayInfo()
{
    cout << "Area played in: " << area << endl;
    cout << "Number of players: " << numPlayers << endl;
    cout << "Points per score: " << perScore << endl;
    cout << "Number of matches: " << numMatches << endl;
    cout << "Points per set: " << perSet << endl;
    cout << "Net height: " << netHeight << endl;
}

void volleyball::displayInfo()
{
    cout << "Area played in: " << area << endl;
    cout << "Number of players: " << numPlayers << endl;
    cout << "Points per score: " << perScore << endl;
    cout << "Points per set: " << perSet << endl;
    cout << "Net height: " << netHeight << endl;
}

int main()
{
    string best;
    cout << "What sport do you wish to see information about?\n";
    cout << "The options are: (f)ootball, (s)occer, (t)ennis or (v)olleyball?\n";
    cin >> best;
    sport *x;
    if(tolower(best[0]) == 'f')
    {
        x = new football();
    }
    else if(tolower(best[0]) == 's')
    {
        x = new soccer();
    }
    else if(tolower(best[0]) == 't')
    {
        x = new tennis;
    }
    else
    {
        x = new volleyball;
    }
    x->displayInfo();
    delete x;
}
