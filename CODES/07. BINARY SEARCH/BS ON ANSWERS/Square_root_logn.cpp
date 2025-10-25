#include <bits/stdc++.h>
using namespace std;

// BruteForce--> using linear search. Time Complexity - O(n)
class Solution
{
public:
    int mySqrt(int x)
    {
        int ans = 1;
        for (int i = 1; i <= x; i++)
        {
            if (i * i <= x)
            {
                ans = i;
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};

// Optimal Solution --> Using binary search. Time Complexity - O(log n)
class Solution
{
public:
    int mySqrt(int x)
    {

        int left = 0;
        int right = x;
        while (left <= right)
        {
            long long mid = (left + right) / 2;
            long long val = mid * mid;
            if (val <= x)
            {
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        return right;
    }
    // Note --> you can store the answer in variable or simply return the high as it will be pointing to most favourable answer.
};
