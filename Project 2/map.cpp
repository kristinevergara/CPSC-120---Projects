/*
Dahlia Sukaik <dahliasukaik@csu.fullerton.edu>
Kristine Vergara <kvergara@csu.fullerton.edu>
Kris Nguyen <kris.guyen2204@csu.fullerton.edu> */

#include "helper_code.hpp"
#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>



using std::string;
using std::endl;
using std::cout;
using std::cin;

const int ROW = 100;
const int COL = 100;
//global constants

bool loadMapFile (std::string file, char (&arr)[ROW][COL], int& width, int& height);
void gotoxy (short x, short y);
bool checkPlayerDead (char (&arr)[ROW][COL], int& x, int& y);
bool doDeathEnd (char (&arr)[ROW][COL], int& x, int& y);
bool checkPlayerGold (char (&arr)[ROW][COL], int& x, int& y);
bool checkPlayerWin (char (&arr)[ROW][COL], int& x, int& y);
void get_player_move(char input, char (&maze)[ROW][COL], int& x, int& y, bool& player, int& coin);
void renderPlayer(char (&arr)[ROW][COL],int& x, int& y);
void renderWall(char (&arr)[ROW][COL], int& width, int& height, int& player_x, int& player_y);
//prototypes


//function
bool loadMapFile(string file_name, char (&arr)[ROW][COL], int& width, int& height)
{

    std::ifstream file;
    char next;
    int x = 0, y = 0;
    //cordinates
    file.open(file_name);
    if(!file)
    {
      cout << "Cannot open file";
      //telling user the file is unable to open
    }
    else
    {
      while (file.get(next))
      {
        if (!file.eof()/*if the end of the file is reached*/)
         {
           if (next != '\n'/*if the next character read is not \n*/)
             {
                arr[x][y] = next;
                x++;
                width = x;
                //setting the width to x
             }
           else if (next == '\n'/*if the next character read is \n*/)
             {
                arr[x][y] = next;
                y++;
                x = 0;
                height++;
                //making x = 0 and increasing the y and height values 
             }
         }
         else
           {
             cout << "Error while loading file" << endl;
             //telling user the file can't open
             return false;
             //making the program quit
           }
      }

      return true;
      //letting program run sucessfully
    } 

  return false;
  //making program return false entirely
}
