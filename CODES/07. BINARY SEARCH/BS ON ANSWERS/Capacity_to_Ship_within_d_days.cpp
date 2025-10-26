#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool possible(vector<int> &nums, int days, int capacity)
    {
        int load = 0;
        int day = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (load + nums[i] > capacity)
            {
                day++;
                load = nums[i];
            }
            else
            {
                load += nums[i];
            }
        }
        return day <= days;
    }
    int shipWithinDays(vector<int> &weights, int days)
    {
        int n = weights.size();
        int left = *max_element(weights.begin(), weights.end());
        long long right = accumulate(weights.begin(), weights.end(), 0);
        int ans = right;

        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (possible(weights, days, mid))
            {
                ans = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return ans;
    }
};