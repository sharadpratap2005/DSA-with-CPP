#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
                return mid;

            // duplicates handle
            if (nums[mid] == nums[left] && nums[mid] == nums[right])
            {
                left++;
                right--;
                continue;
            }
            //  left half sorted
            if (nums[left] <= nums[mid])
            {
                if (target >= nums[left] && target <= nums[mid])
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            // right half sorted
            else
            {
                if (target >= nums[mid] && target <= nums[right])
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