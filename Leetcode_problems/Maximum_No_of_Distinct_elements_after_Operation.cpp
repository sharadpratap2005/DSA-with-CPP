/* We sort the array and from the first element we try to get the minimal possible no after adding -k to it. if it is possible we do it*/
class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int count=0;
        int n = nums.size();
        int prev = INT_MIN;
        for (int i = 0; i < n; i++) {
            int minValue = nums[i] - k;
            if (prev < minValue) {
                prev = minValue;
                count++;
            } else if (prev < nums[i] + k) {
                prev = prev + 1;
                count++;
            }
        }
        return count;
    }
};
