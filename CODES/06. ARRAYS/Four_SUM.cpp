// 4 SUM

// BruteForce--> using for loops. Time Complexity - O(n^4). Note, during sum --> sum=arr[i]+arr[j]; sum+=arr[k];sum+=arr[l]; don't add all in single line to avoid the integer limit

// Better Approach--> using hashset to store the unique quadrlets. Time Complexity -> O(n3)*log m
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ans;
        set<vector<int>> st;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                set<int> Hashset;
                for (int k = j + 1; k < n; k++)
                {
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    int fourth = target - sum;
                    if (Hashset.find(fourth) != Hashset.end())
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k], fourth};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                    Hashset.insert(nums[k]);
                }
            }
        }
        ans.assign(st.begin(), st.end());
        return ans;
    }
};

// Optimal Solution--> we will use two pointers fixed (i & j) and two pointers move (k & l).
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < n; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                int k = j + 1;
                int l = n - 1;
                while (k < l)
                {
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];

                    if (sum == target)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        while (k < l && nums[k] == nums[k - 1])
                            k++;
                        while (k < l && nums[l] == nums[l + 1])
                            l--;
                    }
                    else if (sum < target)
                        k++;
                    else
                        l--;
                }
            }
        }
        return ans;
    }
};