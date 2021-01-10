#include<iostream>

using namespace std;
#define NAME_SIZE 10

typedef struct
{
    float real;
    float imaginary;
}complex;


complex comp_add(complex a, complex b)
{
    complex c;
    c.real = a.real + b.real;
    c.imaginary = a.imaginary + b.imaginary;

    return c;
}
int main()
{
    complex c1, c2;
    complex result = comp_add(c1,c2);
    cout<<result.real<<" + "<<result.imaginary<<"i\n";
    return 0;
}

