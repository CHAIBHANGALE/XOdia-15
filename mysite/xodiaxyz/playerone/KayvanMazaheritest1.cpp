#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// working with enums are easier !
enum State {EMPTY = 0, OWN_LEAF = 1, ENEMY_LEAF = 2, OWN_NODE = 3, ENEMY_NODE = 4, OWN_FROZEN = 5, ENEMY_FROZEN = 6};
typedef pair<int, int> point;
#define X first
#define Y second

// each dot in the game board is a Cell
struct Cell
{
    bool direction[8];
    State state;

    // constructor
    Cell(){
        std::fill(direction, direction+8, false);
        state = EMPTY;
    }

    // fills the properties with a given input string s
    void fill(string s)
    {
        state = State(s[0] - '0');
        for(int i=0; i<8; i++)
            direction[i] = (bool)(s[i+1] - '0');
        return;
    }
};


////////////////////////////////////////////////////////////////////////////////
/////////////////////////// Global Variables ///////////////////////////////////

// This is the actual 20 * 20 game board
Cell board[20][20];

// We store our own leaves here (NOTE: doesn't include frozen leaves!)
vector<point> ownLeaves;


////////////////////////////////////////////////////////////////////////////////
///////////////////////// Functions Prototypes /////////////////////////////////

void readInput();   // Reads the input from stdin
void readBoard();   // Reads the board and does some preprocessing
void doFirstMove(); // do the first moev
void move();        // AI goes here
//State int2state(int);


////////////////////////////////////////////////////////////////////////////////
///////////////////////////// Main Function ////////////////////////////////////
//##############################################################################
int main()
{
    readInput();
    readBoard();
    move();
    return 0;
}
//##############################################################################
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
////////////////////// Functions Implementationes //////////////////////////////

// Reads the input from stdin
void readInput()
{
    // cerr << "Reading Input Started" << endl;
    string inputString;
    cin >> inputString;
    int counter = 0;
    for(int i=0; i<20; i++)
        for(int j=0; j<20; j++)
        {
            string input = inputString.substr(counter * 9, 9);
            board[i][j].fill(input);
            counter++;
        }
    // cerr << "Reading Input Finished" << endl;
    return;
}

// Reads the board and does some preprocessing
void readBoard()
{
    // cerr << "Reading Board Started" << endl;
    for(int i=0; i<20; i++)
        for(int j=0; j<20; j++)
        {
            if(board[i][i].state == OWN_LEAF)
                ownLeaves.push_back(point(i, j));
        }
    // cerr << "Reading Board Finished" << endl;
    return;
}

// Do the first move
void doFirstMove()
{
    std::cout << "10,0,10,1" << std::endl;
    return;
}

// AI goes here
void move()
{
    if(ownLeaves.empty())
    {
        // cerr << "ownLeaves is empty!" << endl;
        doFirstMove();
        return;
    }
    cout <<ownLeaves[0].X<< ","  << ownLeaves[0].Y<< ","  <<ownLeaves[0].X+1<< ","  << ownLeaves[0].Y+1 << ","  << ownLeaves[0].X-1 << ","  << ownLeaves[0].Y+1 << endl;
    ownLeaves[0]=point(10,1);
    // printf("%d,%d,%d,%d,%d,%d\n",ownLeaves[0].X, ownLeaves[0].Y,ownLeaves[0].X+1, ownLeaves[0].Y+1,ownLeaves[0].X-1, ownLeaves[0].Y+1 );

    return;
}
