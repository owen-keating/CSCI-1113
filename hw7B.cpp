//
//  main.cpp
//  hw7B
//
//  Created by Owen Keating on 4/2/21.
//

#include <iostream>
using namespace std;

const int SIZE = 10;
const string NOT_VALID = "INVALID";

class creature{ // things!
public:
    creature();
    creature(string n, int h, int d, int g);
    string getName();
    void attack(creature& other); // for hurting other creatures
    bool isDead(); // checks to see if you have enoug hp
    int getHP();
    int getDMG();
    void starve();
    int getHunger();
    void setHunger(int g);
    void setLocation(int r, int c); // sets your location in the world
    bool move(char dir, creature& you); // changes location based on "wasd"
    int getRowLocation();
    int getColLocation();
    void kill(); // no more creature...
private:
    string name;
    int hp;
    int dmg;
    int hunger;
    int worldRow;
    int worldCol;
};

class world{
public:
    world();
    void show(); // displaying the world (and everything on it)
    char getTile(int r, int c);  //shows what is displayed in the world at a row/col
    creature& getCreature(int r, int c); // returning creature& as I don't want multiple copies of this creature
    creature& getCreature(string name); // ^^ (probably better to use pointers, but this homework isn't about them)
    void addCreature(creature &c);// keep track of another creature
    void processTile(); // figuring out the hero should do at a tile of the map
private:
    void setRow(int r, string s); // used to help initialize map
    creature list[SIZE*SIZE+1]; // last creature is invalid
    int creatureCount; // how many creatures are in the list
    char map[SIZE][SIZE];
};

void clearScreen();
void processTile(world& w);
void gotoTown(creature& you);
void round(creature& attacker, creature& getHit);
bool isFirstLetter(string s, string tests);

int main()
{
    string hname; // your name! (or something cool)
    do
    {
        cout << "Who art thou? (Don't start with 'R' or '~' or '.')\n";
        getline(cin,hname);
    }while(hname.length() == 0 || isFirstLetter(hname, "r~."));

    creature heroine = creature(hname, 10, 1, 10);
    heroine.setLocation(6,5);
    
    world island;
    island.addCreature(heroine); // heroine is always first creature
    
    // make a rabbit
    creature rabby = creature("Rabbit", 2, 1, 10);
    rabby.setLocation(8, 3);
    island.addCreature(rabby); // save rabbit in the world
    
    // ... and some more rabbits
    creature rabby2 = creature("Rabbit", 2, 1, 10);
    rabby2.setLocation(4, 8);
    island.addCreature(rabby2); // save rabbit in the world

    creature rabby3 = creature("Rabbit", 2, 1, 10);
    rabby3.setLocation(5, 8);
    island.addCreature(rabby3); // save rabbit in the world

    creature rabby4 = creature("Rabbit's Revenge", 2, 9, 10);
    rabby4.setLocation(4, 8);
    island.addCreature(rabby4); // save rabbit in the world

    while(!island.getCreature(hname).isDead()) // keep going until you drop
    {
        // show where you are:
        clearScreen();
        island.show();
        
        // show how healthy you are:
        cout << "HP: " << island.getCreature(hname).getHP() << endl;
        cout << "Hunger: " << island.getCreature(hname).getHunger() << endl;
        // ask what you want to do:
        cout << "Which direction do you want to move ('w'=up, 'a'=left, 's'=down, 'd'=right)?  ";
        string dir;
        getline(cin, dir);
        if(dir.length()>0) // if they didn't just hit enter
        {
            if(dir[0] == 'q') // quit
            {
                island.getCreature(hname).kill(); // =(
                break;
            }
            // process your movement, then interact with that tile
            island.getCreature(hname).move(dir[0], island.getCreature(hname));
            island.processTile();
        }
    }
        
    cout << "Game over...\n";
}

// hack solution
void clearScreen()
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

// interacting with town
void gotoTown(creature& you)
{
    clearScreen();
    cout << "                                +" << endl;
    cout << "                               / \\" << endl;
    cout << "          ______   ___________/ o \\" << endl;
    cout << "________  |    |   |               |   /^\\" << endl;
    cout << "| * * *|  |: ::|   |               |  //^\\\\" << endl;
    cout << "| * *  |  |::  |   | []  []  []  []|  ((|))" << endl;
    cout << "|*  ** |  |:  :|   | []  []  []    |  ((|))" << endl;
    cout << "|_[]___|  |_||_|   |____________;;_|    | " << endl;

    // not a whole lot to do here...
    cout << you.getName() << " walks into town, but there is nothing to do here and leaves.\n";
    
    cout << "(press enter to continue...)";
    string x;
    getline(cin, x);
}

void garden(creature& you){
    clearScreen();
    cout << "          \\   /" << endl;
    cout << "...  ...   \\@/" << endl;
    cout << "_:_  _:_    |" << endl;
    cout << "\\_/  \\_/   / \\" << endl;
    cout << " v    v   |   |" << endl;
    
    cout << "A grandma with a suspiciously long nose says: 'O great " << you.getName() << ", have a feast of carrots to help vanquish those evil rabbits'.\n";
    you.setHunger(7);
    cout << "Once you are satiated, you venture back out into the wilderness...\n";
    cout << "(press enter to continue...)";
    string x;
    getline(cin, x);
}

// creature "a" and "b" fighting ("a" is the heroine)
void battle(creature& a, creature& b)
{
    clearScreen();
    cout << "      ___/________" <<endl;
    cout << "        /    \\  \\" <<endl;
    cout << "   @___/      \\@/" <<endl;
    cout << "  /\\__/        |" <<endl;
    cout << " / \\ /        / \\" <<endl;
    cout << "/  /          |  \\" <<endl;

    int turn=0; // creatures alternate turns attacking
    while(!a.isDead() && !b.isDead())
    {
        // creature a (heroine) goes first (on even turns)
        if(turn%2==0)
        {
            round(a,b);
        }
        else // monster goes on odd turns
        {
            round(b,a);
        }
        turn++; // next turn
    }
    
    // figure out who won
    if(a.isDead())
    {
        cout << a.getName() << " perishes.\n";
    }
    else
    {
        cout << b.getName() << " perishes.\n";
    }
    
    cout << "(press enter to continue)";
    string x;
    getline(cin, x);
}

// apply damage and display the info
void round(creature& attacker, creature& getHit)
{
    attacker.attack(getHit);
    cout << attacker.getName() << " smacks " << getHit.getName() << " for " << attacker.getDMG() << " damage.";
    cout << "(press enter to continue...)";
    string x;
    getline(cin, x);
}

// see if "s"'s first charater is in tests
bool isFirstLetter(string s, string tests)
{
    for(int i=0; i < (int)tests.length(); i++)
    {
        if(tolower(s.at(0)) == tests.at(i))
        {
            return true;
        }
    }
    
    return false;
}

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// -=-=- Creature class stuff below  -=-
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

// invalid creatures
creature::creature()
{
    name = NOT_VALID;
    hp = 0;
    dmg = 0;
}

// more useful constructor
creature::creature(string n, int h, int d, int g)
{
    name = n;
    hp = h;
    dmg = d;
    hunger = g;
}

string creature::getName()
{
    return name;
}

void creature::attack(creature& other)
{
    other.hp -= dmg;
}

bool creature::isDead()
{
    return hp <= 0;
}

int creature::getHP()
{
    return hp;
}

int creature::getDMG()
{
    return dmg;
}

void creature::starve()
{
    hp--;
}

int creature::getHunger()
{
    return hunger;
}

void creature::setHunger(int g)
{
    hunger+=g;
}

void creature::setLocation(int r, int c)
{
    worldRow = r;
    worldCol = c;
}

// "wasd" to move
bool creature::move(char dir, creature& you)
{
    if(tolower(dir) == 'w') // up
    {
        worldRow = max(0, worldRow-1); // ensure it doesn't go outside the valid array
        if(you.getHunger()>0)
        {
            you.setHunger(-1);
        }
        else
        {
            you.starve();
        }
        return true;
    }
    else if(tolower(dir) == 's') // down
    {
        worldRow = min(SIZE-1, worldRow+1);
        if(you.getHunger()>0)
        {
            you.setHunger(-1);
        }
        else
        {
            you.starve();
        }
        return true;
    }
    else if(tolower(dir) == 'a') // left
    {
        worldCol = max(0, worldCol-1);
        if(you.getHunger()>0)
        {
            you.setHunger(-1);
        }
        else
        {
            you.starve();
        }
        return true;
    }
    else if(tolower(dir) == 'd') // right
    {
        worldCol = min(SIZE-1, worldCol+1);
        if(you.getHunger()>0)
        {
            you.setHunger(-1);
        }
        else
        {
            you.starve();
        }
        return true;
    }
    else
    {
        return false;
    }
}

int creature::getRowLocation()
{
    return worldRow;
}

int creature::getColLocation()
{
    return worldCol;
}

void creature::kill()
{
    hp=0;
}

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// -=-=-=- World class stuff below -=-=-
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

world::world()
{
    creatureCount=0; // start with no creatures
    
    // setup the basic map:
    setRow(0, "~~~~~~~~~~");
    setRow(1, "~~~~~~..~~");
    setRow(2, "~~~~~~...~");
    setRow(3, "~~~~~~...~");
    setRow(4, "~~~~~....~");
    setRow(5, "~~~~..G..~");
    setRow(6, "~~~.....~~");
    setRow(7, "~~~...T.~~");
    setRow(8, "~~~....~~~");
    setRow(9, "~~~~~~~~~~");
}

char world::getTile(int r, int c)
{
    return map[r][c];
}

void world::setRow(int r, string s)
{
    for(int i=0; i < (int)s.length() && i < SIZE; i++)
    {
        map[r][i] = s.at(i);
    }
}

void world::show()
{
    // temp char array to put creatures over basic map
    char currentWorld[SIZE][SIZE];
    
    // copy all the basic map elements
    for(int i=0; i < SIZE; i++)
    {
        for(int j=0; j < SIZE; j++)
        {
            currentWorld[i][j] = map[i][j];
        }
    }
    
    // draw any (alive) creatures here
    for(int i=creatureCount-1; i >= 0; i--) // going backwards so hero is on top of other creatures
    {
        if(list[i].getRowLocation() >= 0 && list[i].getRowLocation() < SIZE && list[i].getColLocation() >= 0 && list[i].getColLocation() < SIZE && !list[i].isDead())
        {
            currentWorld[list[i].getRowLocation()][list[i].getColLocation()] = tolower(list[i].getName().at(0));
        }
    }
    
    // draw map (with creatures)
    for(int i=0; i < SIZE; i++)
    {
        for(int j=0; j < SIZE; j++)
        {
            cout << currentWorld[i][j];
        }
        cout << endl;
    }

}

creature& world::getCreature(int r, int c)
{
    for(int i=creatureCount-1; i >= 0; i--) // since heroine is always list[0], we want to check this last so we can tell if heroine is ontop of something else
    {
        if(list[i].getRowLocation() == r && list[i].getColLocation() == c && !list[i].isDead()) // only return alive creatures
        {
            return list[i];
        }
    }
    
    return list[SIZE*SIZE]; // if we don't find anything, return a default creature
}

creature& world::getCreature(string name)
{
    for(int i=creatureCount-1; i >= 0; i--) // since heroine is always list[0], we want to check this last so we can tell if heroine is ontop of something else
    {
        if(list[i].getName() == name && !list[i].isDead())
        {
            return list[i];
        }
    }
    
    return list[SIZE*SIZE]; // if we don't find anything, return a default creature
}

void world::addCreature(creature &c)
{
    list[creatureCount] = c; // list is partiallyed filled array
    creatureCount++;
}

void world::processTile()
{
    // find which tile the heroine is on
    int pRow = list[0].getRowLocation();
    int pCol = list[0].getColLocation();
    
    
    if(map[pRow][pCol] == '~') // if they on the ocean
    {
        cout << "The heroic " << list[0].getName() << " walks in to the ocean wearing heavy armor and joins the fishes...\n";
        list[0].kill();
    }
    else if(map[pRow][pCol] == 'T') // if heroine in town
    {
        gotoTown(list[0]);
    }
    else if(map[pRow][pCol] == 'G')
    {
        garden(list[0]);
    }
    else // see if the heroine is on top of a monster (to fight)
    {
        for(int i=1; i < creatureCount; i++)
        {
            if(list[0].getRowLocation() == list[i].getRowLocation() && list[0].getColLocation() == list[i].getColLocation() && !list[i].isDead()) // fight if they on same row/col and monster alive
            {
                battle(list[0], list[i]);
                break; // only fight a monster once per tile
            }
        }
    }
}
