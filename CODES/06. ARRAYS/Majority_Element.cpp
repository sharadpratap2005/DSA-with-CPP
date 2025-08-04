// Given the array. find the number having frequency greater than the n/2.
#include <bits/stdc++.h>
using namespace std;

// BruteForce--> using linear search. Time Complexity -> O(n^2).

// Better--> Using HashMap to find the number having frequency greater than the n/2. Time Complexity - O(2n) & Space Complexity - O(n)
int Majority_Element_Better(int arr[], int n)
{
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }
    for (auto it : freq)
    {
        if (it.second > n / 2)
        {
            return it.first;
        }
    }
    return -1;
}

// Optimal--> Moore's Voting Algorithm
int Majority_Element_Optimal(int arr[], int n)
{
    int count = 0;
    int element;
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            count = 1;
            element = arr[i];
        }
        else if (arr[i] == element)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    int count_freq;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == element)
        {
            count_freq++;
        }
    }
    if (count_freq > n / 2)
    {
        return element;
    }
    return -1;
}

int main()
{
    int arr[] = {2, 2, 1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    // int ans = Majority_Element_Better(arr, n);
    int ans = Majority_Element_Optimal(arr, n);

    cout << ans << endl;

    return 0;
}