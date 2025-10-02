#include <bits/stdc++.h>
using namespace std;

// BruteForce --> we will check the every element if it is unique return it. Time Complexity - O(n).
class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
        {
            return nums[0];
        }

        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                if (nums[i] != nums[i + 1])
                    return nums[i];
            }
            else if (i == n - 1)
            {
                if (nums[i] != nums[i - 1])
                {
                    return nums[i];
                }
            }
            else
            {
                if (nums[i] != nums[i + 1] && nums[i] != nums[i - 1])
                {
                    return nums[i];
                }
            }
        }
        return -1;
    }
};

// Optimal Solution --> Using Binary Search Time Complexity - O(log n)
class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        // handle the edge casesssc
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if (nums[0] != nums[1])
            return nums[0];
        if (nums[n - 1] != nums[n - 2])
            return nums[n - 1];

        int left = 1;
        int right = n - 2;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1])
                return nums[mid];

            if (mid % 2 == 0)
            {
                if (nums[mid - 1] == nums[mid])
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else
            {
                if (nums[mid - 1] == nums[mid])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};