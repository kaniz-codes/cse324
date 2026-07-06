#include <cctype>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;

    if (op == '*' || op == '/')
        return 2;

    return 0;
}

string infixToPostfix(string infix)
{
    string answer = "";
    stack<char> box;

    for (char c : infix)
    {
        if (c == ' ')
            continue;

        if (isalnum(c))
        {
            answer += c;
        }
        else if (c == '(')
        {
            box.push(c);
        }
        else if (c == ')')
        {
            while (!box.empty() && box.top() != '(')
            {
                answer += box.top();
                box.pop();
            }

            if (!box.empty())
                box.pop();
        }
        else
        {
            while (!box.empty() &&
                   box.top() != '(' &&
                   precedence(box.top()) >= precedence(c))
            {
                answer += box.top();
                box.pop();
            }

            box.push(c);
        }
    }

    while (!box.empty())
    {
        answer += box.top();
        box.pop();
    }

    return answer;
}

string postfixToPrefix(string postfix)
{
    stack<string> box;

    for (char c : postfix)
    {
        if (isalnum(c))
        {
            box.push(string(1, c));
        }
        else
        {
            string right = box.top();
            box.pop();

            string left = box.top();
            box.pop();

            box.push(string(1, c) + left + right);
        }
    }

    return box.top();
}

int main()
{
    string infix;

    cout << "Enter an infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    string prefix = postfixToPrefix(postfix);

    cout << "Postfix: " << postfix << endl;
    cout << "Prefix: " << prefix << endl;

    return 0;
}