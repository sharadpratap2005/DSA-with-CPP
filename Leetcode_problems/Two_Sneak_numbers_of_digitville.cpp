class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> mpp;
        for (int val : nums) {
            mpp[val]++;
            if (mpp[val] == 2)
                ans.push_back(val);
        }
        return ans;
    }
};
