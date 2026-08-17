#include <bits/stdc++.h>
using namespace std;

map<char, vector<string>> G;
map<char, set<char>> FIRST, FOLLOW;
map<char, map<char, string>> table;

char startSymbol;

bool isNT(char c)
{
    return c >= 'A' && c <= 'Z';
}

set<char> firstString(string s)
{
    set<char> ans;

    if (s == "#")
    {
        ans.insert('#');
        return ans;
    }

    for (char c : s)
    {
        if (!isNT(c))
        {
            ans.insert(c);
            return ans;
        }

        for (char x : FIRST[c])
            if (x != '#')
                ans.insert(x);

        if (!FIRST[c].count('#'))
            return ans;
    }

    ans.insert('#');
    return ans;
}

void findFirst()
{
    bool change = true;

    while (change)
    {
        change = false;

        for (auto p : G)
        {
            char A = p.first;

            for (string rhs : p.second)
            {
                set<char> f = firstString(rhs);

                for (char x : f)
                    if (FIRST[A].insert(x).second)
                        change = true;
            }
        }
    }
}

void findFollow()
{
    FOLLOW[startSymbol].insert('$');

    bool change = true;

    while (change)
    {
        change = false;

        for (auto p : G)
        {
            char A = p.first;

            for (string rhs : p.second)
            {
                for (int i = 0; i < rhs.size(); i++)
                {
                    char B = rhs[i];

                    if (!isNT(B))
                        continue;

                    string beta = rhs.substr(i + 1);

                    if (beta != "")
                    {
                        set<char> f = firstString(beta);

                        for (char x : f)
                        {
                            if (x != '#')
                            {
                                if (FOLLOW[B].insert(x).second)
                                    change = true;
                            }
                        }

                        if (f.count('#'))
                        {
                            for (char x : FOLLOW[A])
                                if (FOLLOW[B].insert(x).second)
                                    change = true;
                        }
                    }
                    else
                    {
                        for (char x : FOLLOW[A])
                            if (FOLLOW[B].insert(x).second)
                                change = true;
                    }
                }
            }
        }
    }
}

void makeTable()
{
    for (auto p : G)
    {
        char A = p.first;

        for (string rhs : p.second)
        {
            set<char> f = firstString(rhs);

            for (char x : f)
                if (x != '#')
                    table[A][x] = rhs;

            if (f.count('#'))
                for (char x : FOLLOW[A])
                    table[A][x] = rhs;
        }
    }
}

string showStack(stack<char> s)
{
    string x = "";

    while (!s.empty())
    {
        x += s.top();
        s.pop();
    }

    return x;
}

void parse(string input)
{
    input += '$';

    stack<char> st;
    st.push('$');
    st.push(startSymbol);

    int i = 0;

    cout << "\nStack\tInput\tAction\n";
    cout << "--------------------------------\n";

    while (!st.empty())
    {
        char top = st.top();
        char current = input[i];

        cout << showStack(st) << "\t"
             << input.substr(i) << "\t";

        if (top == current)
        {
            if (top == '$')
            {
                cout << "Accepted\n";
                cout << "\nString is accepted\n";
                return;
            }

            cout << "Match " << current << endl;

            st.pop();
            i++;
        }

        else if (isNT(top))
        {
            if (!table[top].count(current))
            {
                cout << "No Rule\n";
                cout << "\nString is not accepted\n";
                return;
            }

            string rhs = table[top][current];

            cout << top << "->" << rhs << endl;

            st.pop();

            if (rhs != "#")
            {
                for (int j = rhs.size() - 1; j >= 0; j--)
                    st.push(rhs[j]);
            }
        }

        else
        {
            cout << "Mismatch\n";
            cout << "\nString is not accepted\n";
            return;
        }
    }
}

int main()
{
    int n;

    cout << "Enter number of productions: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string p;
        cin >> p;

        char lhs = p[0];
        string rhs = p.substr(3);

        G[lhs].push_back(rhs);

        if (i == 0)
            startSymbol = lhs;
    }

    findFirst();
    findFollow();
    makeTable();

    string input;

    cout << "Enter string: ";
    cin >> input;

    parse(input);

    return 0;
}