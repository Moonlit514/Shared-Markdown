#include <iostream>
#include <string>
#include <stack>

bool isValid(std::string s)
{
    std::stack<char> stk;
    for (char c : s)
    {
        if (c == '(' || c == '{' || c == '[')
        {
            stk.push(c);
        }
        else
        {
            if (stk.empty())
                return false;
            char top = stk.top();
            stk.pop();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '['))
            {
                return false;
            }
        }
    }
    return stk.empty();
}

int main()
{
    std::string s;
    std::cout << "Enter a string of parentheses: ";
    std::cin >> s;
    if (isValid(s))
    {
        std::cout << "The parentheses are valid." << std::endl;
    }
    else
    {
        std::cout << "The parentheses are not valid." << std::endl;
    }
    return 0;
}