#include <iostream>
#include <algorithm>
using namespace std;
void quick_sort(int *begin, int *end)
{
    // Choose an element to be pivot, then divide the elements into two parts, one is smaller then pivot, one is bigger.
    // Recursiviely do it until it's sorted.
    if (begin >= end)
        return;
    auto pivot = *begin; // choose the first element as the pivot
    auto i = begin;      // 1. elements on the right side of i should bigger then pivot
    auto j = end;        // 2. elements on the left side of j should be smaller then pivot
    do
    {
        do
        {
            i++;
        } while (*i < pivot && i < end); // find the first i that *i is bigger then pivot
        do
        {
            j--;
        } while (*j > pivot && j < end); // find the first j that *j is smaller then pivot
        if (i < j)
        {
            // *i should be bigger then pivot now and *j should be smaller then pivot now
            swap(*i, *j); // so we swap *i and *j to make sure 1. and 2. are true
        }
    } while (i < j);
    swap(*j, *begin);
    quick_sort(begin, j);
    quick_sort(j + 1, end);
}