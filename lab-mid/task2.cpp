// Write a LEX/C++ program to identify token.
#include<iostream>
#include <string>
using namespace std;

int main(){
    string x;
    cout<<"Enter a word: ";
    cin>> x ;
    if (x == "int"|"main"|"for"|"if"|"else"|"return"|"while")
    {
        cout << "This is a keyword."<<endl;
    }
    else
    {
        cout << "This is not a keyword."<<endl;
    }
}