#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool possible(vector<int> &arr, int day, int m, int k)
    {
        int count = 0;
        int bloom = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] <= day)
            {
                count++;
            }
            else
            {
                bloom += count / k;
                count = 0;
            }
        }
        bloom += count / k;
        if (bloom >= m)
            return true;
        else
            return false;
    }
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int n = bloomDay.size();
        if ((long long)m * k > n)
            return -1;

        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());
        int result = right;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (possible(bloomDay, mid, m, k))
            {
                result = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return result;
    }
};