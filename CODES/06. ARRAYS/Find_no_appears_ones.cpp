#include <bits/stdc++.h>
using namespace std;

// BruteForce--> Linear Search using two forloops.
int Find_no_Brute(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        int num = arr[i];
        for (int j = 0; j < n; j++)
        {
            if (num == arr[j])
            {
                count++;
            }
        }
        if (count == 1)

            return num;
    }
    return -1;
}

// Better--> Using map to store the frequency of all the numbers.
int Find_no_Better(int arr[], int n)
{
    unordered_map<long long, int> Hashmap;
    for (int i = 0; i < n; i++)
    {
        Hashmap[arr[i]]++;
    }
    for (auto it : Hashmap)
    {
        if (it.second == 1)
        {
            return it.first;
        }
    }
    return -1;
}

// Optimal--> Using XOR : a ^ a = 0 and a ^ 0 = a , using this concept to get the single number. T.C O(n) & S.C O(1).
int Find_no_Optimal(int arr[], int n)
{
    int XOR = 0;
    for (int i = 0; i < n; i++)
    {
        XOR = XOR ^ arr[i];
    }
    int ans = XOR;
    return ans;
}

int main()
{
    int arr[] = {1, 1, 8, 8, 9, 9, 2, 2, 3, 4, 4, 5, 5, 6, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    // int ans = Find_no_Brute(arr, n);
    // int ans = Find_no_Better(arr, n);
    int ans = Find_no_Optimal(arr, n);

    cout << "No is " << ans;

    return 0;
}