#include <iostream>
#include <stack>
#include <string>
using namespace std;

float scanNum(char ch)
{
    return float(ch - '0');
}

int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/') return 1;
    return -1;
}

float operation(float b, float a, char op)  // Note the order of a and b
{
    float res = 0;
    switch (op)
    {
    case '+':
        res = a + b;
        break;
    case '-':
        res = a - b;
        break;
    case '*':
        res = a * b;
        break;
    case '/':
        res = a / b;
        break;
    default:
        cout << "Invalid operator" << endl;
        break;
    }
    return res;
}

float postfixEval(string postfix)
{
    stack<float> stk;
    string::iterator it;
    for (it = postfix.begin(); it != postfix.end(); it++)
    {
        if (isOperator(*it) == 1)
        {
            // Pop two operands for the operation
            float a = stk.top(); stk.pop();
            float b = stk.top(); stk.pop();
            stk.push(operation(b, a, *it));  // Push result back on stack
        }
        else
        {
            // If it's not an operator, treat it as a number
            stk.push(scanNum(*it));
        }
    }
    // Final result is the top of the stack
    return stk.top();
}

int main()
{
    string post = "53+62/*35*+";
    cout << "The result is: " << postfixEval(post) << endl;
    return 0;
}
