#include <bits/stdc++.h>
using namespace std;

int cakeTower(int n, int T, int K,
              const vector<int> &h,
              const vector<int> &v)
{
    vector<int> dp_no_big(T + 1, 0);
    for (int i = 0; i < n; ++i)
    {
        for (int j = h[i]; j <= T; ++j)
        {
            dp_no_big[j] = max(dp_no_big[j], dp_no_big[j - h[i]] + v[i]);
        }
    }
    int ans = dp_no_big[T];

    vector<int> dp_upper(T + 1, 0);
    for (int i = 0; i < n; ++i)
    {
        if (h[i] < K)
        {
            for (int j = h[i]; j <= T; ++j)
            {
                dp_upper[j] = max(dp_upper[j], dp_upper[j - h[i]] + v[i]);
            }
        }
    }

    vector<int> dp_lower(T + 1, 0);
    for (int i = 0; i < n; ++i)
    {
        int compressed_h = (4 * h[i]) / 5;
        for (int j = compressed_h; j <= T; ++j)
        {
            dp_lower[j] = max(dp_lower[j], dp_lower[j - compressed_h] + v[i]);
        }
    }

    for (int i = 0; i < n; ++i)
    {
        if (h[i] < K)
            continue;
        int remaining = T - h[i];
        if (remaining < 0)
            continue;
        for (int x = 0; x <= remaining; ++x)
        {
            int total_val = dp_lower[x] + v[i] + dp_upper[remaining - x];
            if (total_val > ans)
            {
                ans = total_val;
            }
        }
    }

    return ans;
}

void test_sample1()
{
    const int n = 3, T = 53, K = 25;
    vector<int> h = {25, 5, 10};
    vector<int> v = {100, 20, 40};
    int yourAns = cakeTower(n, T, K, h, v);
    int bestAns = 240;
    cout << "Your answer is " << yourAns << ", while the best answer is " << bestAns << endl;
}

void test_sample2()
{
    const int n = 15, T = 100, K = 100;
    vector<int> h = {
        5, 70, 45, 90, 10, 25, 5, 5, 75, 35, 55, 10, 60, 5, 90};
    vector<int> v = {
        18467, 26500, 15724, 29358, 24464, 28145, 16827,
        491, 11942, 5436, 14604, 153, 12382, 18716, 19895};
    int yourAns = cakeTower(n, T, K, h, v);
    int bestAns = 374320;
    cout << "Your answer is " << yourAns << ", while the best answer is " << bestAns << endl;
}