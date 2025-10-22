class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int result = 1;
        unordered_map<int, int> freq;
        int n = nums.size();
        // using the differnece arrray technique
        int maxval = *max_element(nums.begin(), nums.end()) + k;
        vector<int> diffarr(maxval + 2, 0);
        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
            int l = max(nums[i] - k, 0);
            int r = min(nums[i] + k, maxval);
            diffarr[l]++;
            diffarr[r + 1]--;
        }
        // cummulative sum
        for (int target = 0; target <= maxval; target++) {
            diffarr[target] += (target > 0 ? diffarr[target - 1] : 0);
            int targetfreq = freq[target];
            int needconversion = diffarr[target] - targetfreq;
            int maxpossible = min(needconversion, numOperations);
            result = max(result, targetfreq + maxpossible);
        }
        return result;
    }
};
