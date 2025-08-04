#include <bits/stdc++.h>
using namespace std;

// BruteForce--> Using two for loops to check each pair of element to see if the pair adds up to target or not. Time Complexity -> O(n^2).
vector<int> Two_Sum_Brute(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                return {i, j};
            }
        }
    }
    return {-1, 1};
}

// Better--> Using Map Hashing. Time Complexity - O(n * log n) & Space Complexity - O(n)
vector<int> Two_Sum_Better(int arr[], int n, int target)
{
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {

        int num = arr[i];
        int more = target - num;
        if (mpp.find(more) != mpp.end())
        {
            return {mpp[more], i};
        }
        mpp[num] = i;
    }
    return {-1, 1};
}

// Optimal--> Using Two pointers and greedy approach.
bool Two_Sum_Optimal(int arr[], int n, int target)
{
    sort(arr, arr + n);
    int left = 0;
    int right = n - 1;
    while (left < right)
    {
        int sum = arr[left] + arr[right];
        if (sum == target)
        {
            return true;
        }
        else if (sum < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return false;
}

int main()
{
    int arr[] = {2, 3, 5, 1, 9};
    int target = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Given Array & " << "Target = " << target << endl;
    for (int val : arr)
    {
        cout << val << " ";
    }

    vector<int> ans;

    // ans = Two_Sum_Brute(arr, n, target);
    ans = Two_Sum_Better(arr, n, target);
    // bool ans = Two_Sum_Optimal(arr, n, target);
    cout << endl;
    cout << "The Elements which adds to target have indecies " << ans[0] << " and " << ans[1];

    return 0;
}