#include <bits/stdc++.h>
using namespace std;

// Bruteforce --> using for loops and linear search. Time Complexity - O(n^2)
bool linear_search(vector<int> arr, int x)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return true;
        }
    }
    return false;
}
int Longest_sequence_brute(vector<int> arr)
{
    int n = arr.size();
    int longest = 1;
    for (int i = 0; i < n; i++)
    {
        int x = arr[i];
        int count = 1;
        while (linear_search(arr, x + 1) == true)
        {
            x = x + 1;
            count++;
        }
        longest = max(longest, count);
    }

    return longest;
}

// Sorting the array and pointer approach Time Complexity - O(n * log n)+O(n)
int Longest_sequence_better(vector<int> arr)
{
    int n = arr.size();
    int longest = 1;
    int smallest = INT_MIN;
    sort(arr.begin(), arr.end());
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] - 1 == smallest)
        {
            count = count + 1;
            smallest = arr[i];
        }
        else if (arr[i] != smallest)
        {
            count = 1;
            smallest = arr[i];
        }
        longest = max(longest, count);
    }

    return longest;
}

// Using unordered set. Time Complexity - O(3n)
int Longest_sequence_optimal(vector<int> arr)
{
    int n = arr.size();
    if (n == 0)
    {
        return 0;
    }

    int longest = 1;
    unordered_set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(arr[i]);
    }
    for (auto it : st)
    {
        if (st.find(it - 1) == st.end())
        {
            int count = 1;
            int x = it;
            while (st.find(x + 1) != st.end())
            {
                x = x + 1;
                count++;
            }
            longest = max(longest, count);
        }
    }

    return longest;
}

int main()
{
    vector<int> arr = {102, 4, 100, 1, 101, 3, 2, 1, 1};
    // int ans = Longest_sequence_brute(arr);
    // int ans = Longest_sequence_better(arr);
    int ans = Longest_sequence_optimal(arr);

    cout << ans << endl;
    return 0;
}