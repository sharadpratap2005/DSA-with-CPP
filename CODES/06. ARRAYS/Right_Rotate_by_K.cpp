#include <bits/stdc++.h>
using namespace std;

// Optimal approach to decrease space complexity to O(1) but time complexoty increases to O(2n).
void Right_Rotate_OPTIMAL(int arr[], int n, int k)
{
    reverse(arr, arr + n);
    reverse(arr, arr + k);
    reverse(arr + k, arr + n);
}

// Brute force approach---> Time complexity is O(n+d) and (extra) Space complexity is O(d);
void Right_Rotate(int arr[], int n, int k)
{
    k = k % n;
    int temp[k];
    int q = 0;
    // Storing in temp variable
    for (int i = n - 1; i >= n - k; i--)
    {
        temp[q] = arr[i];
        q++;
    }
    // Shifting the k elements
    for (int i = n - k - 1; i >= 0; i--)
    {
        arr[i + k] = arr[i];
    }
    int t = k - 1;
    // Shifting the remain elements
    for (int i = 0; i < k; i++)
    {
        arr[i] = temp[t];
        t--;
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
    Right_Rotate_OPTIMAL(arr, n, k);
    cout << "After Rotation" << endl;
    for (int val : arr)
    {
        cout << val << " ";
    }
    return 0;
}
