//#include "prototypes.hpp"
//#include "defines.hpp"
#include <iostream>
#include "helper_code.hpp"



using std::string;
using std::endl;
using std::cout;


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


//defining game symbols
//void render_game();

/***
 * get_player_move function
 * receiving move, 2d maze array,map actual size x and why and player current position
 * get player current position and store it to the new temporary position x and 
 * if player entered w, decrese player temp_y and check the new temporary position which
 * functions in logic file. If player is not heading to the wall or deadth, decrese y variable
 * if player get gold, increment gold variable, if player win exit the game. store character 
 * 'P' to new maze position.
***/



void get_player_move(char input, char (&maze)[ROW][COL], int& x, int& y, bool& player, int& coin){
        //static int coin = 0;
        //input = getch();
        int temp_x = x, temp_y = y;
        
            switch(input){
                case 'w':
                    temp_y--;
                    if(doDeathEnd(maze,temp_x,temp_y) == true || checkPlayerDead(maze,temp_x,temp_y) == true){
                        if(doDeathEnd(maze,temp_x,temp_y)){
                            cout << "You heading to walls" <<endl;
                            //let user know if they heading the wall
                            maze[x][y] = 'P';
                            break;
                         }else if(checkPlayerDead(maze,temp_x,temp_y)){
                            cout<< "You're dead" << endl;
                            //let the user know they dead
                            player = false;
                            break;
                            //print menu here
                        }
                    }
                    
                    if(checkPlayerGold(maze,temp_x,temp_y)){
                        coin++;
                        //cout << "gold: " << coin << endl;
                    }
                    if(checkPlayerWin(maze,temp_x,temp_y)){
                        cout << "You Win!!!!!" << endl;
                        player = false;
                        break;
                        //print menu here
                    }
                    y--;
                    maze[x][y] = 'P';
                    //cout << x << " " << y << endl;
                break;
                
                case 's':
                    temp_y++;
                    if(doDeathEnd(maze,temp_x,temp_y) == true || checkPlayerDead(maze,temp_x,temp_y) == true){
                        if(doDeathEnd(maze,temp_x,temp_y)){
                            cout << "You heading to walls" <<endl;
                            //let user know if they heading the wall
                            maze[x][y] = 'P';
                            break;
                         }else if(checkPlayerDead(maze,temp_x,temp_y)){
                            cout<< "You're dead" << endl;
                            //let the user know they dead
                            player = false;
                            break;
                            //print menu here
                        }
                    }
                    if(checkPlayerGold(maze,temp_x,temp_y)){
                        coin++;
                        //cout << "gold: " << coin << endl;
                    }
                    if(checkPlayerWin(maze,temp_x,temp_y)){
                        cout << "You Win!!!!!" << endl;
                        player = false;
                        break;
                        //print menu here
                    }
                    y++;
                    maze[x][y] = 'P';
                    //cout << x << " " << y << endl;
                break;
                
                case 'a':
                    temp_x--;
                    if(doDeathEnd(maze,temp_x,temp_y) == true || checkPlayerDead(maze,temp_x,temp_y) == true){
                        if(doDeathEnd(maze,temp_x,temp_y)){
                            cout << "You heading to walls" <<endl;
                            maze[x][y] = 'P';
                            break;
                         }else if(checkPlayerDead(maze,temp_x,temp_y)){
                            cout<< "You're dead" << endl;
                            player = false;
                            break;
                            //print menu here
                        }
                    }
                    if(checkPlayerGold(maze,temp_x,temp_y)){
                        coin++;
                        //cout << "gold: " << coin << endl;
                    }
                    if(checkPlayerWin(maze,temp_x,temp_y)){
                        cout << "You Win!!!!!" << endl;
                        player = false;
                        break;
                        //print menu here
                    }
                    x--;
                    maze[x][y] = 'P';
                    //cout << x << " " << y << endl;
                break;
                
                case 'd':
                temp_x++;
                    if(doDeathEnd(maze,temp_x,temp_y) == true || checkPlayerDead(maze,temp_x,temp_y) == true){
                        if(doDeathEnd(maze,temp_x,temp_y)){
                            cout << "You heading to walls" <<endl;
                            maze[x][y] = 'P';
                            break;
                         }else if(checkPlayerDead(maze,temp_x,temp_y)){
                            cout<< "You're dead" << endl;
                            player = false;
                            break;
                            //print menu here
                        }
                    }
                    if(checkPlayerGold(maze,temp_x,temp_y)){
                        coin++;
                        //cout << "gold: " << coin << endl;
                    }
                    if(checkPlayerWin(maze,temp_x,temp_y)){
                        cout << "You Win!!!!!" << endl;
                        player = false;
                        break;
                        //print menu here
                    }
                    x++;
                    maze[x][y] = 'P';
                    //cout << x << " " << y << endl;
                break;
            }
        
        
}

/***
 * store player previous move and replace that position with a blank
 * and store it to the maze
***/

void renderPlayer(char (&arr)[ROW][COL], int& x, int& y){
    int temp_x = x, temp_y = y;
    arr[temp_x][temp_y] = ' ';
}

/**
 * print out the maze and player new position
**/

void renderWall(char (&arr)[ROW][COL], int& width, int& height, int& player_x, int& player_y){
    for(int i = 0; i<= height; i++){
        for(int j = 0; j < width; j++){
            if(arr[i][j] == 'P'){
                player_x = i;
                player_y = j;
            }
            cout << arr[j][i];
        }
        cout<< endl;
    }
}

