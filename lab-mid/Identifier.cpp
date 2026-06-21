// Write a C/C++ program to recognize valid and invalid identifier.
#include <iostream>
#include <string>

using namespace std;

int main() {
    string word;
    cout << "Enter an identifier: ";
    cin >> word;

    bool isValid = true;

    if (word.empty()) {
        isValid = false;
    } else {
        char first = word;
        if (!isalpha(first) && first != '_') {
            isValid = false;
        }

        for (int i = 1; i < word.length(); i++) {
            if (!isalnum(word[i]) && word[i] != '_') {
                isValid = false;
                break;
            }
        }
    }

    if (isValid) {
        cout << "Valid Identifier" << endl;
    } else {
        cout << "Invalid Identifier" << endl;
    }

    return 0;
}