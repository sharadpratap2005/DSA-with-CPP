#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int ceiling_sum(vector<int> &arr, int num)
    {
        int sum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            sum += (arr[i] + num - 1) / num;
        }
        return sum;
    }
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int n = nums.size();
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = high;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (ceiling_sum(nums, mid) <= threshold)
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