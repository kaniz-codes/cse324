#include<iostream>
#include<string>
using namespace std;

int main(){
    string a;
    cout << "Enter a string: " <<endl;
    cin >> a;

    string keywords[] = {"int", "float", "if", "else", "for", "while"};

    int n = sizeof(keywords) / sizeof(keywords[0]);

    bool found = false;
    for(int i=0; i<n; i++){
        if(a == keywords[i]){
            found = true;
            break;
        }
    }
    if(found){
        cout<<"this is a keyword."<<endl;
    }
    else{
        cout<<"this is not a keyword."<<endl;
    }
}
