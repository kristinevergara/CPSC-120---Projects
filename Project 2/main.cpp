/*
Dahlia Sukaik <dahliasukaik@csu.fullerton.edu>
Kristine Vergara <kvergara@csu.fullerton.edu>
Kris Nguyen <kris.guyen2204@csu.fullerton.edu> */

#include "helper_code.hpp"
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fstream>

using std::cin;
using std::cout;
using std::ifstream;
using std::endl;
using std::string;

const int ROW = 100;
const int COL = 100;

bool loadMapFile (std::string file, char (&arr)[ROW][COL], int& width, int& height);
void gotoxy (short x, short y);
bool checkPlayerDead (char (&arr)[ROW][COL], int& x, int& y);
bool doDeathEnd (char (&arr)[ROW][COL], int& x, int& y);
bool  checkPlayerGold (char (&arr)[ROW][COL], int& x, int& y);
bool checkPlayerWin (char (&arr)[ROW][COL], int& x, int& y);
void get_player_move(char input, char (&maze)[ROW][COL], int& x, int& y, bool& player, int& coin);
void renderPlayer(char (&arr)[ROW][COL],int& x, int& y);
void renderWall(char (&arr)[ROW][COL], int& width, int& height, int& player_x, int& player_y);


/*
main function
displayer a welcome message, ask user for starting the game
creating 2d array with a constant value and send it to the loadMapFile function 
along with a file name
display a map and get user move untill the game is over
*/


int main (int argc, char *argv[])
{
    
    string file = argv[1];

   if (argc > 1) {
        cout << "Compiling game..." << endl;
    }
    else {
        throw std::runtime_error ("No input filename found; Please provide one as the first argument when invoking this program!");
    }
    if (argc == 2) {
        ifstream mapfile;
        mapfile.open (file);
    if (!mapfile) {
      cout << "Error opening file containing map " << endl;
    }
    else {
    
        char maze[ROW][COL];
        //variable to hold maze
        char move;
        //variable in order for player to move 
        int width = 0, height = 0, coin = 0;
        //starting points and intital coin count
        int player_x = 0, player_y = 0;
        //starting coridinates of player
 
 

        string choice;
        cout << "** Welcome to The Maze *" << endl;
        cout << "To move up press w, to move down press s, to move to the right press d, " << endl; 
        cout << "To move to the left press a." << endl;
        cout << "Enter lower case s to play or q to quit the game" << endl;
        cout << "Enter your choice: ";
        //displaying welcome message at start of game
        cin >> choice;
        //getting users input to start or quit the game

        cout << endl;
   
        if(choice == "q")
        {
        cout << "Ok! quiting!" << endl;
        }
        else if (choice == "s")
        {
            loadMapFile(file,maze, width, height);
            bool player = true;

            while (player)
            {
                cout << "Gold: " << coin << endl;
                cout << "your turn ";
                move = getch();

                cout << endl;
                renderPlayer(maze, player_x, player_y);
                get_player_move(move, maze, player_x, player_y, player, coin);
                if (!checkPlayerDead(maze, player_x, player_y))
                {
                    if(checkPlayerWin(maze, player_x, player_y))
                    {
                        cout << "You Wonnn!!!" << endl;
                    }

                    renderWall(maze, width, height, player_x, player_y);
                }
                cout << endl;
            }
     
            cout << "Total coins: " << coin << endl;
            //showing player total coins gained
            cout<<"Game Over!" << endl;
            //telling user the game is over
        }
        else
        {
            cout << "Invalid input!" << endl;
            cout << endl;
            //if player inputs and invalid option
        }
    }
 
 }
  return 0;
}
