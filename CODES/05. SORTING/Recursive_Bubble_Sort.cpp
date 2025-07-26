// Push the Maximum element to the last by swapping the adjacent element repeatedly using recursion.
#include <bits/stdc++.h>
using namespace std;

void Bubble_sort(int arr[], int n)
{
    if (n == 1)
        return;
    for (int i = 0; i <= n - 2; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }
    Bubble_sort(arr, n - 1);
}

int main()
{
    int arr[] = {654, 23, 96, 45, 7, 65, 12, 6, 7, 1, 698};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Sorting the array is: " << endl;
    for (auto val : arr)
    {
        cout << val << " ";
    }
    cout << endl;
    cout << "After Sorting the array is: " << endl;
    Bubble_sort(arr, n);
    for (auto val : arr)
    {
        cout << val << " ";
    }
    return 0;
}