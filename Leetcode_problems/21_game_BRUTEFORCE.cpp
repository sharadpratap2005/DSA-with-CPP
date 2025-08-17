#include <bits/stdc++.h>
using namespace std;
/*  BruteForce Approach-> we will calculate the probaility of 1 to n and store it in array. then we take the recauired probability sum which is from k to n. Note: probability of taking a card from 1 to maxPts is 1/maxPts and will be equal for all the cards.
formula for probability of a number is p(n)=[p(k-1)*1/maxPts]+[p(k-1)*1/maxPts]+[p(k-1)*1/maxPts]+........and so on.
Time Complexity - O(n*maxPts).
 */
class Solution
{
public:
    double new21Game(int n, int k, int maxPts)
    {
        // An array to store the probability of number from 1 to n.
        vector<double> p(n + 1, 0.0);

        // Note: p[0]=1; as given in the question because the points starterd from 0.
        p[0] = 1;

        // finding probability from 1 to n.
        for (int num = 1; num <= n; num++)
        {
            for (int card = 1; card <= maxPts; card++)
            {
                // Note: Keep in mind negative index and boundary limit of k as loop have to stop if the points becomes equal to or greater than k as given in question
                // probability of score card = 1/maxPts;
                // Remain score = p[num-card]
                if ((num - card >= 0) && (num - card) < k)
                {
                    p[num] += p[num - card] / maxPts;
                }
            }
        }
        // Now we just need the probaility of num from k to n only.

        return accumulate(p.begin() + k, p.end(), 0.0);
    }
};
