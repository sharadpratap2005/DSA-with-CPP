// Take an element & place it in the correct position using recursion
#include <bits/stdc++.h>
using namespace std;

void Insertion_sort(int arr[], int i, int n)
{
    if (i == n)
        return;
    int j = i;
    while (j > 0 && arr[j] < arr[j - 1])
    {
        swap(arr[j], arr[j - 1]);
        j--;
    }
    Insertion_sort(arr, i + 1, n);
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
    Insertion_sort(arr, 0, n);
    for (auto val : arr)
    {
        cout << val << " ";
    }
    return 0;
}