// Moving all zeroes to the end using two pointer approach
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {9, 3, 9, 1, 6, 0, 6, 0, 7, 6, 3, 4, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int j = -1;
    // finding first zero index
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            j = i;
            break;
        }
    }
    // shifting the zeroes to the last
    for (int i = j + 1; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
    for (int val : arr)
    {
        cout << val << " ";
    }
    return 0;
}