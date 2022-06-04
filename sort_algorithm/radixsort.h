// Time Complexity
// O(Max-Digit*(Radix-size+n))
#include <iostream>
#include <vector>
using namespace std;
void radix_sort(int *begin, int *end)
{
    int max = *begin;
    for (auto i = begin; i < end; i++)
    {
        if (*i > max)
        {
            max = *i;
        }
    }
    int n = 1;
    while (max > 9)
    {
        max /= 10;
        n *= 10;
    }
    vector<vector<int>> radix(10);
    int r = 1;
    while (r <= n)
    {
        for (auto i = begin; i < end; i++)
        {
            int key = ((*i) / r) % 10;
            radix[key].push_back(*i);
        }
        auto temp = begin;
        for (auto i : radix)
        {
            for (auto j : i)
            {
                *temp = j;
                temp++;
            }
        }
        for (int i = 0; i < 10; i++)
        {
            radix[i].clear();
        }
        r *= 10;
    }
}