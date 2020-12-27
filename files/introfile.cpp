#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    ofstream FILE; //create file object
    FILE.open("tuna.txt");

    FILE << "I love tuna and tuna loves me!\n";
    FILE << "YAY!\n";

    FILE.close();
}