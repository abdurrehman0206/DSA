#include <iostream>
#include <cctype>
#include <stack>
using namespace std;

int precedenceCheck(char);
string inToPost(stack<char>, string);
string inToPre(stack<char>, string);
int main()
{
    string inFix;
    stack<char> s;
    cout << "Enter an infix expression : ";
    cin >> inFix;
    cout << "Infix Expression = " << inFix << endl;
    cout << "Postfix Expression = " << inToPost(s, inFix) << endl;
    // cout << "Prefix Expression = " << preFix << endl;
    system("pause");
    return 0;
}
int precedenceCheck(char op)
{
    if (op == '+' || op == '-')
    {
        return 1;
    }
    else if (op == '*' || op == '/')
    {
        return 2;
    }
    else if (op == '^')
    {
        return 3;
    }
    return -1;
}
string inToPost(stack<char> st, string exp)
{
    string postfix = "";
    for (int i = 0; i < exp.length(); i++)
    {
        if (isalpha(exp[i]) || isdigit(exp[i]))
        {
            postfix += exp[i];
        }
        else if (exp[i] == '(')
        {
            st.push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            while ((st.top() != '(') && (!st.empty()))
            {
                postfix += st.top();
                st.pop();
            }
        }
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '/' || exp[i] == '*' || exp[i] == '^')
        {
            if (st.empty())
            {
                st.push(exp[i]);
            }
            else
            {
                if (precedenceCheck(exp[i]) > precedenceCheck(st.top()))
                {
                    st.push(exp[i]);
                }
                else if (exp[i] == '^' && precedenceCheck(exp[i]) == precedenceCheck(st.top()))
                {
                    st.push(exp[i]);
                }
                else
                {
                    while (!st.empty() && precedenceCheck(exp[i]) <= precedenceCheck(st.top()))
                    {
                        postfix += st.top();
                        st.pop();
                    }
                    st.push(exp[i]);
                }
            }
        }
    }
    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }
    return postfix;
}
string inToPre(stack<char> st, string exp)
{
    string prefix;
    for (int i = 0; i < exp.length(); i++)
    {
    }
    return prefix;
}