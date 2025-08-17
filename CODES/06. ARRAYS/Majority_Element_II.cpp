// Majority Element (>n/3)

/* Optimal Approach--> Onlly two majority element can be possible therefore we track the two numbers and check their occurenece. note order of condition applied should be in correct order.*/
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        // only two number can be possible as majority element
        vector<int> ans;
        int n = nums.size() / 3;
        int num1 = -1, num2 = -1;
        int count1 = 0, count2 = 0;

        for (int val : nums)
        {
            if (val == num1)
            {
                count1++;
            }
            else if (val == num2)
            {
                count2++;
            }
            else if (count1 == 0)
            {
                num1 = val;
                count1 = 1;
            }
            else if (count2 == 0)
            {
                num2 = val;
                count2 = 1;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        int freq1 = 0, freq2 = 0;
        for (int val : nums)
        {
            if (num1 == val)
                freq1++;
            else if (num2 == val)
                freq2++;
        }
        if (freq1 > n)
            ans.push_back(num1);
        if (freq2 > n)
            ans.push_back(num2);

        return ans;
    }
};