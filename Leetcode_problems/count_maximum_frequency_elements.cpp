class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int result = 0;
        int maxFreq = 0;
        unordered_map<int, int> mpp;
        for (int val : nums) {
            mpp[val]++;
            maxFreq = max(mpp[val], maxFreq);
        }
        for (auto it : mpp) {
            if (it.second == maxFreq) {
                result += it.second;
            }
        }
        return result;
    }
};
