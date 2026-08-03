/*E->TE'
E'->+TE'|#
T->FT'
T'->*FT'|#
F->(E)|a

sample input: a+a*a
sample output: String is accepted

sample input: a/a*a
sample output: String is not accepted
*/
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string input;
int idx = 0;

void skipWhitespace() {
    while (idx < input.length() && isspace(input[idx])) {
        idx++;
    }
}

bool E();
bool Edash();
bool T();
bool Tdash();
bool F();

bool E() {
    if (T()) {
        if (Edash())
            return true;
    }
    return false;
}

bool Edash() {
    skipWhitespace();
    if (idx < input.length() && input[idx] == '+') {
        idx++;
        if (T()) {
            if (Edash())
                return true;
        }
        return false;
    }
    return true;
}

bool T() {
    if (F()) {
        if (Tdash())
            return true;
    }
    return false;
}

bool Tdash() {
    skipWhitespace();
    if (idx < input.length() && input[idx] == '*') {
        idx++;
        if (F()) {
            if (Tdash())
                return true;
        }
        return false;
    }
    return true;
}

bool F() {
    skipWhitespace();
    if (idx < input.length() && input[idx] == '(') {
        idx++;
        if (E()) {
            skipWhitespace();
            if (idx < input.length() && input[idx] == ')') {
                idx++;
                return true;
            }
        }
        return false;
    }
    else if (idx < input.length() && input[idx] == 'a') {
        idx++;
        return true;
    }
    return false;
}

int main() {
    getline(cin, input);

    idx = 0;
    skipWhitespace();

    if (E()) {
        skipWhitespace();
        if (idx == input.length()) {
            cout << "String is accepted" << endl;
        } else {
            cout << "String is not accepted" << endl;
        }
    } else {
        cout << "String is not accepted" << endl;
    }

    return 0;
}
