class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        int ans = INT_MAX;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (arr[left] <= arr[right])
            {
                ans = min(ans, arr[left]);
                break;
            }
            // left half sorted
            if (nums[left] <= nums[mid])
            {
                ans = min(nums[left], ans);
                left = mid + 1;
            }
            // right half sorted
            else
            {
                ans = min(nums[mid], ans);
                right = mid - 1;
            }
        }
        return ans;
    }
};