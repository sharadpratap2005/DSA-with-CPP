#include <bits/stdc++.h>
using namespace std;

// Optimal approach to decrease space complexity to O(1) but time complexoty increases to O(2n).
void Left_Rotate_OPTIMAL(int arr[], int n, int k)
{
    reverse(arr, arr + k);
    reverse(arr + k, arr + n);
    reverse(arr, arr + n);
}

// Brute force approach---> Time complexity is O(n+d) and (extra) Space complexity is O(d);
void Left_Rotate(int arr[], int n, int k)
{
    k = k % n;
    int temp[k];
    for (int i = 0; i < k; i++)
    {
        temp[i] = arr[i];
    }
    for (int i = k; i < n; i++)
    {
        arr[i - k] = arr[i];
    }
    for (int i = n - k; i < n; i++)
    {
        arr[i] = temp[i - (n - k)];
    }
}

int main()
{
    int arr[] = {6, 4, 8, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    cout << "Before Rotation" << endl;
    for (int val : arr)
    {
        cout << val << " ";
    }
    cout << endl;
    Left_Rotate_OPTIMAL(arr, n, k);
    cout << "After Rotation" << endl;
    for (int val : arr)
    {
        cout << val << " ";
    }
    return 0;
}