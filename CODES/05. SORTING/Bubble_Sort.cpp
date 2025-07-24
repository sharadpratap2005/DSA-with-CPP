// Get the minimum element and swap it with the first element.
#include <bits/stdc++.h>
using namespace std;

void Bubble_sort(int arr[], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        int count = 0; // To check if swapping is done or not . if not then break from the loop as the array is already sorted.
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                count = 1;
            }
        }
        if (count == 0)
        {
            break;
        }
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
    Bubble_sort(arr, n);
    for (auto val : arr)
    {
        cout << val << " ";
    }
    return 0;
}