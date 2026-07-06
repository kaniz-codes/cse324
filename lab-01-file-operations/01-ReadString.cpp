#include<iostream>
#include<string>
using namespace std;

int main(){
    string a;
    cout << "Enter a string: " <<endl;
    getline(cin, a);

    int n = a.length();

    if((a[0] == '/' && a[1] == '*') && (a[n-1] == '/' && a[n-2] == '*')){
        cout << "This is a comment." <<endl;
    }
    else if((a[0] == '/' && a[1] == '/')){
        cout << "This is a comment." <<endl;
    }

    else{
        cout << "This is not a comment." <<endl;
    }

}
