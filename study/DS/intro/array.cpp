#include<iostream>

int main()
{
    int n[10]; /* n is an array of 10 integers */
    
    for(int i=0;i<10;i++)
    {
        n[i] = i + 100; 
    }

    for(int i=0; i<10; i++)
        std::cout<<"n["<<i<<"] is "<<n[i]<<std::endl;
    return 0;
}