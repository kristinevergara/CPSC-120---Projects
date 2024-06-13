#include <stdio.h>
#include <string>
#include <iostream>

//Global constants 

const char PLAYER('P');
const char SNAKE('S');
const char COIN('C');
const char WALL('X');
const char EXIT('O');
const char SPACE(' ');
const int ROW = 100;
const int COL = 100;
//protoypes 
bool loadMapFile (std::string file, char (&arr)[ROW][COL], int& width, int& height);
void gotoxy (short x, short y);
bool checkPlayerDead (char (&arr)[ROW][COL], int& x, int& y);
bool doDeathEnd (char (&arr)[ROW][COL], int& x, int& y);
bool  checkPlayerGold (char (&arr)[ROW][COL], int& x, int& y);
bool checkPlayerWin (char (&arr)[ROW][COL], int& x, int& y);
void get_player_move(char input, char (&maze)[ROW][COL], int& x, int& y, bool& player, int& coin);
void renderPlayer(char (&arr)[ROW][COL],int& x, int& y);
void renderWall(char (&arr)[ROW][COL], int& width, int& height, int& player_x, int& player_y);



bool checkPlayerDead(char (&arr)[ROW][COL], int& x, int& y){
    if(arr[x][y] == SNAKE){
        return true;
    }
    return false;
}

bool doDeathEnd(char (&arr)[ROW][COL], int& x, int& y){
    if(arr[x][y] == 'X'){
        return true;
    }
    return false;
}

bool checkPlayerGold(char (&arr)[ROW][COL], int& x, int& y){

    if(arr[x][y] == COIN){
        return true;
    }
    return false;
}

bool checkPlayerWin(char (&arr)[ROW][COL], int& x, int& y){
    if(arr[x][y] == EXIT){
        return true;
    }
    return false;
}




