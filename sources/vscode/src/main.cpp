#include<iostream>

int main()
{
    int value = 1;
    int* ptr =&value;
    (*ptr)++;
    std::cout<<*ptr<<std::endl;
    return 0;
}