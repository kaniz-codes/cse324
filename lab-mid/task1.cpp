#include <iostream>
#include <string>
using namespace std;

int main(){
    string sentence; //My name is Kaniz
    int Count = 1;

    cout << "Enter a sentence: ";
    getline(cin, sentence);

    for(int i = 0; i<sentence.length(); i++){
        if(sentence[i] == ' '){
            Count++;
        }
    }
    cout << "Total words: "<< Count <<endl;
}