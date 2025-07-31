#include <bits/stdc++.h>
using namespace std;

// Better Approach-->Using Hashing, also map data strucure can be used to store.
int Find_no_Better(int arr[], int n)
{
    int answer = 0;
    int hash[n + 1] = {0};
    for (int i = 0; i < n - 1; i++)
    {
        hash[arr[i]] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        if (hash[i] == 0)
        {
            answer = i;
            break;
        }
    }
    return answer;
}

// Optimal Approach--> Using SUM.
int Find_no_Optimal_SUM(int arr[], int n)
{
    int sum = (n * (n + 1)) / 2;
    int sum_arr = 0;

    for (int i = 0; i < n - 1; i++)
    {
        sum_arr += arr[i];
    }
    return sum - sum_arr;
}

// Another Optimal approach--> Using XOR.
int Find_no_Optimal_XOR(int arr[], int n)
{
    int ans = 0;
    int xor_1 = 0; // Given array
    int xor_2 = 0; // Complete assumed array
    for (int i = 0; i < n - 1; i++)
    {
        xor_1 = xor_1 ^ arr[i];
        xor_2 = xor_2 ^ (i + 1);
    }
    xor_2 = xor_2 ^ n;
    ans = xor_1 ^ xor_2;
    return ans;
}

int main()
{
    int n = 5;
    int arr[] = {1, 2, 4, 5};
    // int result = Find_no_Better(arr, n);
    // int result = Find_no_Optimal_SUM(arr, n);
    int result = Find_no_Optimal_XOR(arr, n);
    cout << "Missing Number is " << result << endl;
    return 0;
}