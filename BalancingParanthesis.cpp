#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    stack<int> stack;
    string input1;
    cout << "Enter the expression";
    cin >> input1;
    int flag1 = 1;

    for (int i = 0; i < input1.size(); i++)
    {
        if ((input1[i] == '(') || (input1[i] == '[') || (input1[i] == '{'))
        {
            stack.push(input1[i]);
        }
        else if ((((input1[i] == ')') && (stack.top() == '(')) || ((input1[i] == '}') && (stack.top() == '{')) || ((input1[i] == ']') && (stack.top() == '['))) && !(stack.empty()))
        {
            stack.pop();
        }
        // else if (stack.empty())
        //     flag1 = 1;
        else
        {
            flag1 = 0;
            break;
        }
    }

    if (flag1)
        cout << "Parenthesis balanced";
    else
        cout << "Paranthesis unbalanced";
    return 0;
}