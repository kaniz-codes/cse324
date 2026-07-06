#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
//=========Write File===========

    ofstream myFile("text.txt");

    if(myFile.is_open())
    {
        myFile << "My name is Kaniz Fatema.\n";
        myFile << "//Kaniz Fatema.\n";
        myFile << "/*Kaniz Fatema.*/\n";

        myFile.close();
        cout<<"Mission successful!!"<<endl;
    }
    else
    {
        cout<<"Error: file not open"<<endl;
    }
//=========Read File===========

    ifstream inFile("text.txt");
    string line;

    if(!inFile.is_open())
    {
        cout<<"Error: Could not open"<<endl;
    }


    while(getline(inFile,line))
    {
        cout<<line<<endl;

        int n = line.length();

        if((line[0] == '/' && line[1] == '*') && (line[n-1] == '/' && line[n-2] == '*'))
        {
            cout << "This is a comment." <<endl;
        }
        else if((line[0] == '/' && line[1] == '/'))
        {
            cout << "This is a comment." <<endl;
        }

        else
        {
            cout << "This is not a comment." <<endl;
        }
    }

    inFile.close();

}

