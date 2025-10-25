#include <bits/stdc++.h>
using namespace std;
/*Given two numbers N and M, find the Nth root of M. The Nth root of a number M is defined as a number X such that when X is raised to the power of N, it equals M. If the Nth root is not an integer, return -1.
 */
class Solution
{
public:
    int NthRoot(int N, int M)
    {
        int low = 1;
        int high = M;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            int val = pow(mid, N);

            if (val == M)
                return mid;
            if (val < M)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
};
