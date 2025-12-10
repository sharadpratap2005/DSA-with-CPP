class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        // Since the answer may be large, return it modulo 109 + 7.
        int M = 1e9 + 7;
        int ans = 0;
        int n = nums.size();
        unordered_map<int, int> left;
        unordered_map<int, int> right;
        // store all the elements in the right map
        for (int val : nums) {
            right[val]++;
        }
        int left_count = 0, right_count = 0;
        for (int i = 0; i < n; i++) {
            int curr = nums[i];
            right[curr]--;
            left_count = left[2 * curr];
            right_count = right[2 * curr];

            ans = (ans + (1LL * left_count * right_count)) % M;
            left[curr]++;
        }
        return ans;
    }
};
