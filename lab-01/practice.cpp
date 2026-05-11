#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
    ofstream myFile("text.txt");

    if(myFile.is_open()){
        myFile << "My name is Kaniz Fatema.\n";
        myFile << "//Kaniz Fatema.\n";
        myFile << "/*Kaniz Fatema.*/\n";

        myFile.close();
        cout<<"Mission successful!!"<<endl;
    }
    else{
        cout<<"Error: file not open"<<endl;
    }

    ifstream inFile("text.txt");
    string line;

    if(!inFile.is_open()){
        cout<<"Error: Could not open"<<endl;
    }


    while(getline(inFile,line)){
        cout<<line<<endl;
    }

    inFile.close();
}
