#include<iostream>

using namespace std;

void fun(int a)
{
    cout<<"value of a is "<<a<<endl;
}
int main()
{
    
    //char a = 'A', b = 'B';
    /*
    const char *ptr = &a;

    cout<<"value pointed to by ptr "<<*ptr<<endl;
    ptr = &b;
    cout<<"value pointed to by ptr "<<*ptr<<endl;
    */
    /*
    char *const ptr = &a;
    cout<<"value pointed to by ptr "<<*ptr<<endl;
    cout<<"address ptr is pointing to "<<&ptr<<endl;

    *ptr = b;
    cout<<"value pointed to by ptr "<<*ptr<<endl;
    cout<<"address ptr is pointing to "<<&ptr<<endl;
    */
   void (*fun_ptr)(int) = &fun;
   (*fun_ptr)(12);

    return 0;   
}