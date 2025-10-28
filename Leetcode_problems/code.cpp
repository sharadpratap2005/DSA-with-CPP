class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int curr = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                curr = i;
            }
            bool flag = true;
            while (curr >= 0 && curr <= n - 1) {
                bool flag = true;
                if (nums[curr] == 0 && flag)
                    curr++;
                if (nums[curr] == 0 && !flag)
                    curr--;
                else if (nums[curr] > 0) {
                    nums[curr]--;
                    if (flag == true) {
                        flag = false;
                    } else {
                        flag = true;
                    }
                }
            }
            int count = 0;
            for (int i = 0; i < n; i++) {
                if (nums[i] != 0)
                    count++;
            }
            if (count == 0)
                ans++;
        }
        return ans;
    }
};
