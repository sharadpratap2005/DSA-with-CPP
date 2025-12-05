class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0); // total sum
        int left_sum = 0;                                  // left sum
        int right_sum = 0;                                 // right sum
        int ans = 0; // count the partitions

        // iterate through the array till n-2 and find the possible pairs
        for (int i = 0; i < n - 1; i++) {
            left_sum += nums[i];
            right_sum = sum - left_sum;
            if ((left_sum - right_sum) % 2 == 0)
                ans++;
        }
        return ans;
    }
};
