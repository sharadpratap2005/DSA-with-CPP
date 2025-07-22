/*Given an array of n integers, find the most frequent element in it i.e., the element that occurs the maximum number of times. If there are multiple elements that appear a maximum number of times, find the smallest of them*/
class Solution
{
public:
    int mostFrequentElement(vector<int> &nums)
    {
        unordered_map<int, int> freq;
        for (auto it : nums)
        {
            freq[it]++;
        }
        int max_freq = INT_MIN;
        int ans = INT_MAX;
        for (auto it : freq)
        {
            if (it.second > max_freq)
            {
                max_freq = it.second;
                ans = it.first;
            }
            else if (it.second == max_freq)
            {
                ans = min(ans, it.first);
            }
        }
        return ans;
    }
};