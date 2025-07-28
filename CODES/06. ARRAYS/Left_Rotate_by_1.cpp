#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {6, 4, 8, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int temp = arr[0];
    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}