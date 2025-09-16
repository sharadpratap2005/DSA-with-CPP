// Binary search---> General Template T.C - O(log n)
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int start = 0;
        int end = n - 1;
        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (target > nums[mid])
            {
                start = mid + 1;
            }
            else if (target < nums[mid])
            {
                end = mid - 1;
            }
            else
            {
                return mid;
            }
        }
        return -1;
    }
};