// Merge Intervals
#include <bits/stdc++.h>
using namespace std;


// BruteForce--> using sorting and check pairs if end is lesser extened it.
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &nums)
    {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            int start = nums[i][0];
            int end = nums[i][1];

            if (!ans.empty() && end <= ans.back()[1])
                continue;

            for (int j = i + 1; j < n; j++)
            {
                if (nums[j][0] <= end)
                    end = max(nums[j][1], end);
                else
                    break;
            }
            ans.push_back({start, end});
        }
        return ans;
    }
};

//Optimal Approach--> just directly check without 2nd loop 
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (ans.empty() || ans.back()[1] < nums[i][0]) {
                ans.push_back(nums[i]);
            } else {
                ans.back()[1] = max(ans.back()[1], nums[i][1]);
            }
        }
        return ans;
    }
};