// Return the index of the target element in an array else return -1.
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int target = 3;
    int arr[] = {5, 7, 3, 6, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}