// Get the minimum element and swap it with the first element.
#include <bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        swap(arr[min], arr[i]);
    }
};
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
    selection_sort(arr, n);
    for (auto val : arr)
    {
        cout << val << " ";
    }

    return 0;
}