// Given the array containing only the 0,1 and 2. sort the array
#include <bits/stdc++.h>
using namespace std;

// BruteForce--> using merge sort. Time Complexity -> O(n * log n).

// Better--> Using For loop to count the ocuurence of elements. Time Complexity - O(2n) & Space Complexity - O(1)
void sort_Better(int arr[], int n)
{
    int count_0 = 0, count_1 = 0, count_2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            count_0++;
        }
        else if (arr[i] == 1)
        {
            count_1++;
        }
        else
        {
            count_2++;
        }
    }
    for (int i = 0; i < count_0; i++)
    {
        arr[i] = 0;
    }
    for (int i = count_0; i < count_0 + count_1; i++)
    {
        arr[i] = 1;
    }
    for (int i = count_0 + count_1; i < n; i++)
    {
        arr[i] = 2;
    }
}

// Optimal--> Using Two pointers and greedy approach.
void sort_Optimal(int arr[], int n)
{
    int low = 0;
    int mid = 0;
    int high = n - 1;

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main()
{
    int arr[] = {2, 0, 1, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    // sort_Better(arr, n);
    sort_Optimal(arr, n);
    cout << "After Sorting" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}