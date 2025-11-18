#include <vector>
using namespace std;

class DoubleHashTable
{
private:
    vector<unsigned long long> keys;

public:
    DoubleHashTable(int m) : keys(m, 0) {}

    int insert(unsigned long long x)
    {
        int m = keys.size();
        unsigned long long h1 = x % m;
        unsigned long long h2 = 1 + (x % (m - 1));
        for (int j = 0; j < m; j++)
        {
            int pos = (h1 + j * h2) % m;
            if (keys[pos] == 0)
            {
                keys[pos] = x;
                return j;
            }
            else if (keys[pos] == x)
            {
                return -1;
            }
        }
        return -1;
    }
};