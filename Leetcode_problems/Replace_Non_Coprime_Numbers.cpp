class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans;
        for (int val : nums) {
            while (!ans.empty()) {
                int prev = ans.back();
                int curr = val;
                int GCD = gcd(prev, curr);
                if (GCD == 1) {
                    break;
                }
                ans.pop_back();
                int lcm = prev / GCD * curr;
                val = lcm;
            }
            ans.push_back(val);
        }
        return ans;
    }
};
