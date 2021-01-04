#include <fstream>
#include <iostream>
#include <string>

using namespace std;
int main(int argc, char* argv[])
{
    ofstream myFile("db.txt",ios::app);
    ifstream read("db.txt");
    string name,title,date;
    char i = '\0';

    if(read.peek() == EOF)
        myFile<<"DATABASE"<<endl<<endl;
    while(i != 'n')
    {
        cout<<"enter a title: ";
        getline(cin,title); 

        cout<<"enter a name: ";
        cin>>name;

        cout<<"enter a date(m/d/y): ";
        cin>>date;

        myFile<<endl<<date<<" | \""<<title<<"\" -"<<name<<"-"<<endl;
        
        cout<<"need to store more? y/n : ";
        cin>>i;

        cin.ignore();
    }

    myFile.close();
    return 0;
}