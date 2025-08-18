// BruteForce--> using three for loops to check every pair. Time complexity->O(n^3)

// Better Solution--> using set data structure & hashing to store the unique pair only. time complexity -> O(n^2) and space complexity -> O(n).
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &arr)
    {
        vector<vector<int>> ans;
        set<vector<int>> st;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            set<int> hashset;
            for (int j = i + 1; j < n; j++)
            {
                int third = -(arr[i] + arr[j]);
                if (hashset.find(third) != hashset.end())
                {
                    vector<int> temp = {arr[i], arr[j], third};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashset.insert(arr[j]);
            }
        }
        ans.assign(st.begin(), st.end());
        return ans;
    }
};

// Optimal solution--> using two pointer approach after sorting the given array
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1, k = n - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0) {
                    j++;

                } else if (sum > 0) {
                    k--;

                } else {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }
                    while (j < k && nums[k] == nums[k + 1]) {
                        k--;
                    }
                }
            }
        }
        return ans;
    }
};