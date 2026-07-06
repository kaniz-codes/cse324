/*
#include <iostream>
#include <string>
#include <stack>
*/
#include <bits/stdc++.h>
using namespace std;

string getRule(char nonTerminal, char terminal) {
    if (nonTerminal == 'A' && terminal == 'a') return "aCa";
    if (nonTerminal == 'C' && terminal == 'b') return "bC";
    if (nonTerminal == 'C' && terminal == 'a') return "#";
    return "";
}

int main() {
    string input = "abba$";
    stack<char> s;

    s.push('$');
    s.push('A');

    int ip = 0;

    cout << "Input String: " << input << endl << endl;
    cout << "Stack\tInput\tAction" << endl;
    cout << "------------------------" << endl;

    while (!s.empty()) {
        char top = s.top();
        char current = input[ip];

        stack<char> temp = s;
        while (!temp.empty()) {
            cout << temp.top();
            temp.pop();
        }
        cout << "\t" << input.substr(ip) << "\t";

        if (top == current) {
            if (top == '$') {
                cout << "Accepted!" << endl;
                cout << "\nSuccess: String is valid." << endl;
                return 0;
            }
            cout << "Match '" << current << "'" << endl;
            s.pop();
            ip++;
        }
        else if (top >= 'A' && top <= 'Z') {
            string rhs = getRule(top, current);

            if (rhs == "") {
                cout << "Rejected (No Rule)" << endl;
                break;
            }

            cout << "Output " << top << "->" << rhs << endl;
            s.pop();

            if (rhs != "#") {
                for (int j = rhs.length() - 1; j >= 0; j--) {
                    s.push(rhs[j]);
                }
            }
        }
        else {
            cout << "Rejected (Mismatch)" << endl;
            break;
        }
    }

    cout << "\nError: String is invalid." << endl;
    return 0;
}
