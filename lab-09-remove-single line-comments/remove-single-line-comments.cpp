#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    //=========Write File===========
    ofstream myFile("input.txt");

    if(myFile.is_open())
    {
        myFile << "My name is Kaniz Fatema.\n";
        myFile << "//Kaniz Fatema.\n";
        myFile << "/*Kaniz Fatema.*/\n";
        myFile << "/*20245103154.*/\n";
        myFile << "Bangladesh is my country. //I live in Bangladesh.\n";

        myFile.close();
    }

    //=========Read File===========

    ifstream inFile("input.txt");

    if(!inFile.is_open())
    {
        cout << "Error: input.txt file could not be opened!" << endl;
        return 1;
    }

    //=========Output File===========
    ofstream outFile("output.txt");

    string line;

    while(getline(inFile, line))
    {
        size_t pos = line.find("//");

        if (pos != string::npos)
        {

            string cleanLine = line.substr(0, pos);
            outFile << cleanLine << endl;
        }
        else
        {
            outFile << line << endl;
        }
    }


    inFile.close();
    outFile.close();

    cout << "Single-line comments removed successfully!" << endl;

    return 0;
}
