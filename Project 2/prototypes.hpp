//
/*
Dahlia Sukaik <dahliasukaik@csu.fullerton.edu>
Kristine Vergara <kvergara@csu.fullerton.edu>
Kris Nguyen <kris.guyen2204@csu.fullerton.edu> */

#include "defines.hpp"
#include <string>
#include <iostream>


//	Prototypes of logic.cpp

bool loadMapFile(char (&arr)[ROW][COL], int& x, int& y);
void gotoxy (short x, short y);
bool checkPlayerDead (char (&arr)[ROW][COL], int& x, int& y);
bool doDeathEnd (char (&arr)[ROW][COL], int& x, int& y);
int checkPlayerGold (char (&arr)[ROW][COL], int& x, int& y);
bool checkPlayerWin (char (&arr)[ROW][COL], int& x, int& y);
void get_player_move (char input, char (&maze)[ROW][COL], int& x, int& y);
char renderPlayer (char (&arr)[ROW][COL], int& x, int& y);
void renderWall (char (&arr)[ROW][COL]);


#endif
