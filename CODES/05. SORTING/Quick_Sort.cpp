// Divide and Conquer it---> Pick an pivot element and place it in the correct position then smaller on the left side and larger on the right side and do it repeatedly using recursion.
#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;
    while (i < j)
    {
        while (arr[i] <= pivot && i <= high - 1)
        {
            i++;
        }
        while (arr[j] > pivot && j >= low + 1)
        {
            j--;
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

void quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int partition_index = partition(arr, low, high);
        quick_sort(arr, low, partition_index - 1);
        quick_sort(arr, partition_index + 1, high);
    }
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
    quick_sort(arr, 0, n - 1);
    for (auto val : arr)
    {
        cout << val << " ";
    }

    return 0;
}