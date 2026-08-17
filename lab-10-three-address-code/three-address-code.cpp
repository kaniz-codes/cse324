#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string expr = "a+b-c*d";
    int tempCount = 1;

    cout << "Input Expression: " << expr << endl;
    cout << "\nThree Address Code:" << endl;

    string arg1 = string(1, expr[0]);

    for (size_t i = 1; i < expr.length(); i += 2) {
        char op = expr[i];
        string arg2 = string(1, expr[i + 1]);
        string res = "t" + to_string(tempCount++);

        cout << res << " = " << arg1 << " " << op << " " << arg2 << endl;

        arg1 = res;
    }

    return 0;
}
