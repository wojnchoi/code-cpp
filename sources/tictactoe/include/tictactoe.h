#ifndef TICTACTOE_H
#define TICTACTOE_H

#include<iostream>

class tictactoe
{
private:

   char num[9] = {'1','2','3','4','5','6','7','8','9'};
   char square[3][3] = {{'1','2','3'},
                       {'4','5','6'},
                        {'7','8','9'}};
public:
    char** createboard();
    void printboard(char** board);
    char** place(char move, char** board, char player, int* turn);
    char checkwin(char** board);
    int checkdraw(char** board);
};
#endif