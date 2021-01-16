#include<iostream>
#define N 5
#define items 3
void insert(int array[], int loc, int val)
{
    for(int i=items; i>=loc;i--)
    {
        array[i+1] = array[i];
    }
    
    array[loc] = val;
}

int main()
{
    int array[N] = {1,2,3}; 
    insert(array, 0, 5);
    for(int i=0; i<N;i++)
    std::cout<<array[i]<<" ";
    std::cout<<std::endl;
    return 0;
}