#include <bits/stdc++.h>
using namespace std;

// BruteForce--> Generate all subarrays. Time Complexity -> O(n^2).
int Max_Length_Brute(int arr[], int n, int k)
{
    int length = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == k)
            {
                length = max(length, j - i + 1);
            }
        }
    }
    return length;
}

// Better--> Using Map Hashing. Time Complexity - O(n * log n) & Space Complexity - O(n)
int Max_Length_Better(int arr[], int n, int k)
{
    map<int, int> PreSumMap;
    int max_length = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == k)
        {
            max_length = max(max_length, i + 1);
        }

        int rem_sum = sum - k;
        // if rem_sum is found in the map then update the length
        if (PreSumMap.find(rem_sum) != PreSumMap.end())
        {
            int length = i - PreSumMap[rem_sum];
            max_length = max(length, max_length);
        }
        // if sum is not present in the map then insert the sum in map with index i
        if (PreSumMap.find(sum) == PreSumMap.end())
        {
            PreSumMap[sum] = i;
        }
    }
    return max_length;
}

// Optimal--> Using Two pointers and greedy approach.
int Max_Length_Optimal(int arr[], int n, int k)
{
    int left = 0;
    int right = 0;
    int sum = arr[0];
    int max_length = 0;
    while (right < n)
    {
        while (left <= right && sum > k)
        {
            sum -= arr[left];
            left++;
        }
        if (sum == k)
        {
            max_length = max(max_length, right - left + 1);
        }
        right++;
        if (right < n)
        {
            sum += arr[right];
        }
    }
    return max_length;
}

int main()
{
    int arr[] = {2, 3, 5, 1, 9};
    int k = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int length = 0;
    // length = Max_Length_Brute(arr, n, k);
    // length = Max_Length_Better(arr, n, k);
    length = Max_Length_Optimal(arr, n, k);

    cout << "Maximum length of longest subarray with sum " << k << " is " << length;

    return 0;
}