#include <bits/stdc++.h>
using namespace std;

// Bruteforce--->time complexity O(maxi-mini*n)
class Solution
{
public:
    bool possible(vector<int> &nums, int distance, int cows)
    {
        int last = nums[0];
        int cowscount = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] - last >= distance)
            {
                cowscount++;
                last = nums[i];
            }
        }
        if (cowscount >= cows)
            return true;
        else
            return false;
    }
    int aggressiveCows(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int limit = nums[n - 1] - nums[0];

        // maximum minimum distance between two cow can be from 1 to (maxi-mini).
        for (int i = 1; i <= limit; i++)
        {
            if (possible(nums, i, k))
                continue;

            else
                return i - 1;
        }
        return limit;
    }
};
#include <bits/stdc++.h>
using namespace std;

// Optimal--->time complexity O(n*logn)
class Solution
{
public:
    bool possible(vector<int> &nums, int distance, int cows)
    {
        int last = nums[0];
        int cowscount = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] - last >= distance)
            {
                cowscount++;
                last = nums[i];
            }
        }
        if (cowscount >= cows)
            return true;
        else
            return false;
    }
    int aggressiveCows(vector<int> &nums, int k)
    {
        int ans = 1;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int limit = nums[n - 1] - nums[0];
        // maximum minimum distance between two cow can be from 1 to (maxi-mini).
        int low = 1;
        int high = limit;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (possible(nums, mid, k))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return ans;
    }
};