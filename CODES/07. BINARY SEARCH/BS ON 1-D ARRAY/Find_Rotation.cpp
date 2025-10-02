#include <bits/stdc++.h>
using namespace std;
int find_rotation(vector<int> &nums)
{
    int n = nums.size();
    int ans = INT_MAX;
    int index = -1;
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (nums[left] < nums[right])
        {
            if (nums[left] < ans)
            {
                ans = nums[left];
                index = left;
                break;
            }
        }

        if (nums[left] <= nums[mid])
        {
            if (nums[left] < ans)
            {
                ans = nums[left];
                index = left;
            }
            left = mid + 1;
        }
        else
        {
            if (nums[mid] < ans)
            {
                ans = nums[mid];
                index = mid;
            }
            right = mid - 1;
        }
    }
    return index;
}

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2, 3};
    cout << find_rotation(nums) << endl;
    return 0;
}