#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    long long data[2][2];
} Matrix;

Matrix mat_multiply(Matrix A, Matrix B)
{
    Matrix res = {{{0, 0}, {0, 0}}};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                res.data[i][j] += (A.data[i][k] * B.data[k][j]) % 1000000007; // 防止溢出
            }
        }
    }
    return res;
}

Matrix power(Matrix A, long long n)
{
    Matrix res = {{{1, 0}, {0, 1}}};
    if (n == 0)
    {
        return res;
    }
    res = power(A, n / 2);
    if (n % 2 == 0)
    {
        return mat_multiply(res, res);
    }
    else
    {
        return mat_multiply(mat_multiply(res, res), A);
    }
}

int fibonacci(long long n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    Matrix A = {{{1, 1}, {1, 0}}};
    Matrix res = power(A, n - 1);
    return res.data[0][0];
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", fibonacci(n) % 1000000007); // 输出结果取模
    return 0;
}