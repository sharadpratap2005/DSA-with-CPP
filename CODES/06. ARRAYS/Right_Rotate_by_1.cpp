#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {6, 4, 8, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int temp = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[0] = temp;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}