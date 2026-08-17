#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

map<char, vector<string>> grammar;
string input;

// match a production
bool match(string rule, int pos, int rulePos, int &endPos);

// Try a non-terminal
bool parse(char nt, int pos, int &endPos)
{
    for (string rule : grammar[nt])
    {
        int tempPos;

        // Epsilon
        if (rule == "#")
        {
            endPos = pos;
            return true;
        }

        if (match(rule, pos, 0, tempPos))
        {
            endPos = tempPos;
            return true;
        }
    }

    return false;
}

// Match symbols of a production
bool match(string rule, int pos, int rulePos, int &endPos)
{
    // Production finished
    if (rulePos == rule.length())
    {
        endPos = pos;
        return true;
    }

    char symbol = rule[rulePos];

    // Non-terminal
    if (symbol >= 'A' && symbol <= 'Z')
    {
        int newPos;

        if (parse(symbol, pos, newPos))
        {
            return match(rule, newPos, rulePos + 1, endPos);
        }

        return false;
    }

    // Terminal
    if (pos < input.length() && input[pos] == symbol)
    {
        return match(rule, pos + 1, rulePos + 1, endPos);
    }

    return false;
}

int main()
{
    int n;

    cout << "Enter number of productions: ";
    cin >> n;
    cout << "Use # for epsilon.\n\n";

    char startSymbol;

    for (int i = 0; i < n; i++)
    {
        string p;

        cout << "Production " << i + 1 << ": ";
        cin >> p;

        char lhs = p[0];
        string rhs = p.substr(3);

        grammar[lhs].push_back(rhs);

        if (i == 0)
            startSymbol = lhs;
    }

    cout << "\nEnter input string: ";
    cin >> input;

    int endPos = 0;

    if (parse(startSymbol, 0, endPos) &&
        endPos == input.length())
    {
        cout << "String is accepted";
    }
    else
    {
        cout << "String is not accepted";
    }

    return 0;
}