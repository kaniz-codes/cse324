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
    if (c >= 'A' && c <= 'Z')
        return 1;
    return 0;
}

void first(char c)
{
    for (int i = 0; i < n; i++)
    {
        if (p[i][0] == c)
        {
            char x = p[i][2];

            if (!isNonTerminal(x))
            {
                add(x);
            }
            else
            {
                first(x);
            }
        }
    }
}

void follow(char c)
{
    if (p[0][0] == c)
        add('$');

    for (int i = 0; i < n; i++)
    {
        for (int j = 2; j < p[i].length(); j++)
        {
            if (p[i][j] == c)
            {
                if (j + 1 < p[i].length())
                {
                    char next = p[i][j + 1];

                    if (!isNonTerminal(next))
                    {
                        add(next);
                    }
                    else
                    {
                        first(next);
                    }
                }
                else
                {
                    if (p[i][0] != c)
                        follow(p[i][0]);
                }
            }
        }
    }
}

int main()
{
    char ch;

    cout << "Enter number of productions: ";
    cin >> n;

    cout << "Enter productions:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    cout << "Enter variable: ";
    cin >> ch;

    m = 0;
    first(ch);

    cout << "FIRST(" << ch << ") = { ";
    for (int i = 0; i < m; i++)
        cout << result[i] << " ";
    cout << "}" << endl;

    m = 0;
    follow(ch);

    cout << "FOLLOW(" << ch << ") = { ";
    for (int i = 0; i < m; i++)
        cout << result[i] << " ";
    cout << "}" << endl;

    return 0;
}