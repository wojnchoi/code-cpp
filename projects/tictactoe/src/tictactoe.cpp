#include"tictactoe.h"
#include<cstdlib>
char** tictactoe::createboard()
{
    char** B = (char**)calloc(3,sizeof(char*));
    for(int i=0;i<3;i++)
    {
        B[i] = (char*)calloc(3,sizeof(char));
    }
    for(int j=0;j<3;j++)
    {
        for(int k=0;k<3;k++)
        {
            B[j][k]= square[j][k];
        }
    }
    return B;
}


void tictactoe::printboard(char** board)
{
    for(int i=0;i<3;i++)
    {
        std::cout<<"-------------\n";
        std::cout<<"|";
        for(int j=0;j<3;j++)
        {
            std::cout<<" "<<board[i][j]<<" |";
        }
        std::cout<<"\n";
    }
    std::cout<<"-------------\n";
}

char** tictactoe::place(char move, char** board, char player,int* turn)
{
    system("clear");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j]== move)
            {
                board[i][j] = player;
                if(*turn == 1)
                    *turn = 2;
                else
                    *turn = 1;
                return board;
            }
        }
    }
    std::cout<<"이 칸은 사용할수없습니다.";
    return board;
}
int tictactoe::checkdraw(char** board)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int k=0; k<9;k++)
            {
                if(board[i][j] == num[k])
                    return 1;
            }
        }
    }
    return 0;
}

char tictactoe::checkwin(char** board)
{
    for(int i=0; i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j] == board[(i+1)%3][j] 
                && board[i][j] == board[(i+2)%3][j])
                    return board[i][j];
            else if(board[i][j] == board[i][(j+1)%3]
                && board[i][j] == board[i][(j+2)%3])
                    return board[i][j];
            else if(i == j && board[i][j] == board[(i+1)%3][(j+1)%3]
                && board[i][j] == board[(i+2)%3][(j+2)%3])
                    return board[i][j];
            else if(i+j == 2 && board[i][j] == board[(i+1)%3][(j+2)%3]
                && board[i][j] == board[(i+2)%3][(j+1)%3])
                    return board[i][j];
        }
    }
    return 0;
}