#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    ofstream FILE("beefjerky.txt"); // same thing as FILE.open("beefjerky.txt");

    FILE << "I love the beef!"<<endl;
    
    if(FILE.is_open())
    {
        cout<<"the file is open"<<endl;
    } else
    {
        cout<<"the file is messed up!!!"<<endl;
    }
    
    FILE.close();

    return 0;
}