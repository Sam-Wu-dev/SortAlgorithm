#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> temp;
void merge(int *left_cur, int *left_end, int *right_cur, int *right_end)
{
    int *begin = left_cur;
    int index = 0;
    while (left_cur != left_end && right_cur != right_end)
    {
        if (*left_cur < *right_cur)
        {
            temp[index++] = *(left_cur++);
        }
        else
        {
            temp[index++] = *(right_cur++);
        }
    }
    while (left_cur != left_end)
    {
        temp[index++] = *(left_cur++);
    }
    while (right_cur != right_end)
    {
        temp[index++] = *(right_cur++);
    }
    for (int i = 0; i < index; i++)
    {
        *(begin++) = temp[i];
    }
}
void _merge_sort(int *begin, int *end)
{
    // Divide and couquer
    // 1. Divide the elements into two parts form middle and then sort both parts
    // 2. Merge them together by keep comparing the smallest elements of both parts
    int size = end - begin;
    if (size <= 1)
    {
        return;
    }
    auto middle = begin + size / 2; // find the middle point
    _merge_sort(begin, middle);     // step 1.
    _merge_sort(middle, end);
    merge(begin, middle, middle, end); // step 2.
}
void merge_sort(int *begin, int *end)
{
    temp.resize(end - begin);
    _merge_sort(begin, end);
}