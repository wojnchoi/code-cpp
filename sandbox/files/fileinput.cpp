#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    ofstream FILE("userInfo.txt");
    cout<<"enter name age money"<<endl;
    cout<<"enter ctrl d to quit"<<endl;

    string name;
    int age;
    double money;
    while(cin>>name>>age>>money)
    {
        FILE<<name<<" "<<age<<" "<<money<<"\n";
    }
    FILE.close();
    return 0;
}