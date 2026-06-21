#include<iostream>
#include<stack>
#include<string>
#include<algorithm>

using namespace std;

int precedence(char op){
    if(op == '+' || op == '-')
        return 1;
    if(op == '*' || op == '/')
        return 2;
    return 0;
}

string infixToPostfix(string infix) {
    string postfix = "";
    stack<char> s;

    for (char c : infix){
        if(isalnum(c)){
            postfix += c;
        }
        else if (c == '(') {
            s.push(c);
        }
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
        else{
            while (!s.empty() && precedence(s.top()) >= precedence(c)){
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }
    while(!s.empty()){
        postfix += s.top();
        s.pop();
    }
    return postfix;
}

int main(){
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;
    string result = infixToPostfix(infix);
    cout << "Your postfix result: " << result << endl;
    reverse(result.begin(), result.end());
    cout << "Your prefix result:  " << result << endl; 
}