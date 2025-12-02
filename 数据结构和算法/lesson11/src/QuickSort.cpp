#include <vector>
#include <algorithm>

template <typename RandomIt>
void insertion_sort(RandomIt begin, RandomIt end)
{
    for (auto i = begin + 1; i != end; ++i)
    {
        auto key = *i;
        auto j = i - 1;
        while (j >= begin && *j > key)
        {
            *(j + 1) = *j;
            --j;
        }
        *(j + 1) = key;
    }
}

template <typename RandomIt>
void quick_sort_helper(RandomIt begin, RandomIt end)
{
    const int n0 = 16;
    while (end - begin > n0)
    {
        auto mid = begin + (end - begin) / 2;
        if (*begin > *mid)
            std::iter_swap(begin, mid);
        if (*begin > *(end - 1))
            std::iter_swap(begin, end - 1);
        if (*mid > *(end - 1))
            std::iter_swap(mid, end - 1);

        auto pivot = *mid;

        auto i = begin - 1;
        auto j = end;
        while (true)
        {
            do
            {
                ++i;
            } while (*i < pivot);
            do
            {
                --j;
            } while (*j > pivot);
            if (i >= j)
                break;
            std::iter_swap(i, j);
        }

        if (j - begin < end - j - 1)
        {
            quick_sort_helper(begin, j + 1);
            begin = j + 1;
        }
        else
        {
            quick_sort_helper(j + 1, end);
            end = j + 1;
        }
    }

    insertion_sort(begin, end);
}
template <typename T>
void quick_sort(std::vector<T> &a)
{
    if (!a.empty())
    {
        quick_sort_helper(a.begin(), a.end());
    }
}