#include <bits/stdc++.h>
#include <conio.h>
#include <string.h>
#include <cstring>
#include <stack>
using namespace std;

bool isOperand(char ch)
{
  if (isalpha(ch) || isdigit(ch))
  {
    return true;
  }
  else
  {
    return false;
  }
}

int precedence(char op)
{
  if (op == '+' || op == '-')
  {
    return 3;
  }
  else if (op == '*' || op == '/')
  {
    return 2;
  }
  else if (op == '^')
  {
    return 1;
  }
  else
  {
    return -1;
  }
}
string infixToPostfix(string inFix)
{
  stack<char> s;
  string postFix;
  for (int i = 0; i < inFix.length(); i++)
  {
    char oneBit = inFix[i];
    if (isOperand(oneBit))
    {
      postFix += oneBit;
    }
    else
    {
      while (!s.empty() && (precedence(s.top()) > precedence(oneBit)))
      {

        postFix += s.top();
        s.pop();
      }
      if (s.empty() || oneBit != ')')
      {
        s.push(oneBit);
      }
      else
      {
        s.pop();
      }
    }
  }
  while (!s.empty())
  {
    postFix += s.top();
    s.pop();
  }
  return postFix;
}
string infixToPrefix(string inFix)
{
  stack<char> s;
  string preFix;
  for (int i = inFix.length(); i >= 0; i--)
  {
    char oneBit = inFix[i];
    if (isOperand(oneBit))
    {
      preFix += oneBit;
    }
    else
    {
      while (!s.empty() && (precedence(s.top()) > precedence(oneBit)))
      {

        preFix += s.top();
        s.pop();
      }
      if (s.empty() || oneBit != '(')
      {
        s.push(oneBit);
      }
      else
      {
        s.pop();
      }
    }
  }
  while (!s.empty())
  {
    preFix += s.top();
    s.pop();
  }
  reverse(preFix.begin(), preFix.end());
  return preFix;
}
int main()
{
  string postFix = "", inFix = "";
  char ch;
  cout << "Input Infix String : ";
  while (true)
  {
    ch = getche();
    if (ch == 13)
    {
      break;
    }
    else if (ch != ',' || ch != ' ')
    {
      inFix += ch;
    }
  }

  cout << endl;
  cout << "Infix : " << inFix << endl;
  cout << "Postfix : " << infixToPostfix(inFix) << endl;
  cout << "Prefix : " << infixToPrefix(inFix) << endl;
  system("pause");
  return 0;
}