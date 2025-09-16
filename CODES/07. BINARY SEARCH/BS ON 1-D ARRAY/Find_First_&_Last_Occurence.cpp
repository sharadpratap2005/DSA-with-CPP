// Find the first and last occurence of the given target value
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        // it checks element is present or not if not then return {-1,-1};
        if (!binary_search(nums.begin(), nums.end(), target))
            return {-1, -1};
        // above thing can be handled by this
        // if(start==n||arr[start]!=target) return {-1,-1};
        int start = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int end = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        return {start, end - 1};
    }
};
// brute force linear search can be done to find the first and last occurence of the target