#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Type
{
    char op;
    double num;
};

double calcRPN(const vector<Type> &expr)
{
    vector<double> stack;
    for (const auto &t : expr)
    {
        if (t.op == '#')
        {
            stack.push_back(t.num);
        }
        else
        {
            double b = stack.back();
            stack.pop_back();
            double a = stack.back();
            stack.pop_back();
            double result;
            switch (t.op)
            {
            case '+':
                result = a + b;
                break;
            case '-':
                result = a - b;
                break;
            case '*':
                result = a * b;
                break;
            case '/':
                result = a / b;
                break;
            case '^':
                result = pow(a, b);
                break;
            }
            stack.push_back(result);
        }
    }
    return stack.back();
}

int main()
{
    vector<Type> expr;
    expr.push_back({'#', 3.0});
    expr.push_back({'#', 5.0});
    expr.push_back({'#', 2.0});
    expr.push_back({'-', 0});
    expr.push_back({'*', 0});
    expr.push_back({'#', 7.0});
    expr.push_back({'+', 0});
    expr.push_back({'#', 0.5});
    expr.push_back({'^', 0});
    double ans = calcRPN(expr);
    cout << ans << endl;
    return 0;
}