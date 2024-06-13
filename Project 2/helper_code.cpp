

#include <stdio.h>
#include <termios.h>
#include <unistd.h>


//	Source: https://cboard.cprogramming.com/cplusplus-programming/176666-there-anything-like-_getch.html?highlight=linux+getch
/// reads from keypress, doesn't echo
int getch()
{
    struct termios oldt, newt;
    int ch;
    tcgetattr( STDIN_FILENO, &oldt );
    newt = oldt;
    newt.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newt );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
    return ch;
}


