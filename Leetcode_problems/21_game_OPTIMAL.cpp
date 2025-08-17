#include <bits/stdc++.h>
using namespace std;

/*Optimal Approach--> We will run the loop 1 to n and track the probability sum for the future use as it will help in reducing the time complexity. we will add probability sum till (i < k ) as after this the game has to be stopped ATQ. if (i-MaxPts)>=0 and < k we wil subtract the p[i - maxPts] from the current sum. After k it is same only the last element is removing . for better understanding try to dry run the code  */
class Solution
{
public:
    double new21Game(int n, int k, int maxPts)
    {
        vector<double> p(n + 1, 0.0);
        p[0] = 1;
        double Current_Probability_Sum = (k == 0) ? 0 : 1;
        for (int i = 1; i <= n; i++)
        {
            p[i] = Current_Probability_Sum / maxPts;

            if (i < k)
            {
                Current_Probability_Sum += p[i];
            }
            if ((i - maxPts) >= 0 && (i - maxPts) < k)
            {
                Current_Probability_Sum -= p[i - maxPts];
            }
        }
        accumulate(p.begin() + k, p.end(), 0.0);
    }
};