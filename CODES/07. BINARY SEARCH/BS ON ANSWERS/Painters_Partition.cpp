#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool possible(vector<int> &nums, int maxTime, int painter)
    {
        int painter_count = 1;
        int total_time = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (total_time > maxTime)
                return false;
            if (total_time + nums[i] <= maxTime)
            {
                total_time += nums[i];
            }
            else
            {
                painter_count++;
                total_time = nums[i];
            }
            if (painter_count > painter)
                return false;
        }
        return true;
    }
    int minTime(vector<int> &arr, int k)
    {
        int ans = 0;
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (possible(arr, mid, k))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};