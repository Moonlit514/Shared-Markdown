#include <iostream>

void foo(int &x) // 引用传递，整个过程没有出现复制，提高效率
{
    x = x + 1;
}

int main()
{
    int a = 10;
    foo(a);
    std::cout << "value of a: " << a << std::endl;
    return 0;
}