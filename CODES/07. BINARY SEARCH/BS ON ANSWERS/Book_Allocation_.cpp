#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool possible(vector<int> &nums, int pages, int students)
    {
        int stu_count = 1;
        int pages_count = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > pages)
                return false;

            if (pages_count + nums[i] <= pages)
            {
                pages_count += nums[i];
            }
            else
            {
                stu_count++;
                pages_count = nums[i];
                if (stu_count > students)
                    return false;
            }
        }

        return true;
    }

    int findPages(vector<int> &nums, int m)
    {
        int n = nums.size();
        if (m > n)
            return -1;

        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = -1;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (possible(nums, mid, m))
            {
                ans = mid;
                high = mid - 1; // try smaller max pages
            }
            else
            {
                low = mid + 1; // need larger pages
            }
        }

        return ans;
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {12, 34, 67, 90};
    int students = 2;
    cout << obj.findPages(nums, students);
}
