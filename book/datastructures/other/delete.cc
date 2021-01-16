#include<iostream>
#define N 5
#define ITEMS 3

void delete1(int array[], int loc)
{
    int tmp = array[loc];
    for(int i = loc; i < ITEMS-1;i++)
        array[i] = array[i+1];
    array[ITEMS-1] = 0;
    
}
int main()
{
    int array[N] = {1,2,3};
     delete1(array, 0);
    for(int i=0; i<N;i++)
    std::cout<<array[i]<<" ";
    std::cout<<std::endl;
    return 0;
}