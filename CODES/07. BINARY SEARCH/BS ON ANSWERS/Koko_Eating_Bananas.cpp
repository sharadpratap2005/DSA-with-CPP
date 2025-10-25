#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long count_hours(vector<int> &piles, long long speed)
    {
        long long hours = 0;
        for (int i = 0; i < piles.size(); i++)
        {
            hours += (piles[i] + speed - 1) / speed; // avoids floating-point ceil
        }
        return hours;
    }

    int minEatingSpeed(vector<int> &piles, int h)
    {
        long long low = 1;
        long long high = *max_element(piles.begin(), piles.end());
        long long ans = high;

        while (low <= high)
        {
            long long mid = low + (high - low) / 2;
            long long total_hours = count_hours(piles, mid);

            if (total_hours <= h)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return (int)ans;
    }
};
