#include<iostream>

#include"tictactoe.h"

tictactoe game;

int main()
{
    char** board = game.createboard();
    char winner = '\0';
    char player = '\0';
    char move; int turn = 1;
    system("clear");
    while(!winner && game.checkdraw(board))
    {
        player = (turn%2)?'X':'O';
        game.printboard(board);
        std::cout<<"Player "<<player <<" 원하는 칸의 숫자를 입력하세요: ";
        fflush(stdout);
        std::cin>>move;
        board = game.place(move, board, player, &turn);
        winner = game.checkwin(board);
    }
    
    game.printboard(board);
    if(winner == 'X' || winner == 'O')
    {
        std::cout<<"Player "<<winner<<"가 이겼습니다!!"<<std::endl;
    } else {
        std::cout<<"승자와 패자가없습니다. 무승부로 게임이 종료됩니다."<<std::endl;
    }
    return 0;
}