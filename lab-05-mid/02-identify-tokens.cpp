// Write a C++ program to identify tokens.
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string sentence, w = "";

    cout << "Enter a statement: ";
    getline(cin, sentence);

    sentence += " ";

    for (int i = 0; i < sentence.length(); i++)
    {
        if (sentence[i] != ' ')
        {
            w = w + sentence[i];
        }
        else if (w != "")
        {
            if (w == "int" || w == "float" ||
                w == "char" || w == "double")
            {
                cout << "KEYWORD: " << w << endl;
            }
            else if (w == "+" || w == "-" ||
                     w == "*" || w == "/" || w == "=")
            {
                cout << "OPERATOR: " << w << endl;
            }
            else if (w == ";" || w == "(" || w == ")" ||
                     w == "{" || w == "}")
            {
                cout << "SYMBOL: " << w << endl;
            }
            else if (w[0] >= '0' && w[0] <= '9')
            {
                cout << "NUMBER: " << w << endl;
            }
            else
            {
                cout << "IDENTIFIER: " << w << endl;
            }

            w = "";
        }
    }

    return 0;
}