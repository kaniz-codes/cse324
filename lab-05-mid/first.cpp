#include <iostream>
#include <string>
using namespace std;

string p[20];
int n;
char result[20];
int m = 0;

void add(char c)
{
    for (int i = 0; i < m; i++)
    {
        if (result[i] == c)
            return;
    }
    result[m++] = c;
}

int isNonTerminal(char c)
{
    return (c >= 'A' && c <= 'Z');
}

void first(char c)
{
    for (int i = 0; i < n; i++)
    {
        if (p[i][0] == c)
        {
            char x = p[i][2];

            if (!isNonTerminal(x))
                add(x);
            else
                first(x);
        }
    }
}

int main()
{
    char ch;

    cout << "Enter number of productions: ";
    cin >> n;

    cout << "Enter productions like A=eAx:" << endl;

    for (int i = 0; i < n; i++)
        cin >> p[i];

    cout << "Enter variable: ";
    cin >> ch;

    m = 0;
    first(ch);

    cout << "FIRST(" << ch << ") = { ";
    for (int i = 0; i < m; i++)
        cout << result[i] << " ";
    cout << "}";

    return 0;
}