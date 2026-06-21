// Write a C/C++ program to identify valid keywords.
#include <iostream>
#include <string>

using namespace std;

int main() {
    string word;
    bool found = false;

    string keywords[] = {
        "int", "float", "char", "double", "if", "else", 
        "for", "while", "do", "return", "break", "continue", 
        "switch", "case", "void", "class", "struct"
    };
    int n = sizeof(keywords) / sizeof(keywords[0]);

    cout << "Enter a word: ";
    cin >> word;

    for (int i = 0; i < n; i++) {
        if (word == keywords[i]) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "This is a Keyword.";
    } else {
        cout << "This is not a Keyword.";
    }
}

