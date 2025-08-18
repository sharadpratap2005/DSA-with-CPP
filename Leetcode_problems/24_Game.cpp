/*GAME 24
To solve this problem we will check all the possible pairs with each possible operation the array reduced that can be performed on those two numbers.
step 1: convert the integer value array into double value array for the precision of floating values.
step 2: call the boolean dfs(vector<double> arr) function to return the answer from the main function.
step 3: In dfs() function -> Base Case: if the size of the array is 1 and array[0]=24 return true else false. Note, remember floating point precision to handle.
step 4: Now using two for loops create every possible pair . We can use the inner loop from j = i+1 to arr.size() as same element cannot be used.
step 5: Now store the remaining elements from the array except ith and jth element in the next array. Because operation will be performed on those numbers then those two numbers will reduced to single result .
step 6: Now store  array which have the numbers except ith and jth and it have result of ith and jth after operation performed on it.
step 7: call the compute function for the ith and jth element so that every possible operation can be performed on these two numbers.
Note, compute() function will return the array which have the result after every operation performed on ith and jth numbers.
step 8: After adding the result value got from compute function to the next array using for loop. call dfs(next) . if it is true then return true.
step 9: If above statement is not true, remove the last element from the next array as this operation will not leads the result to 24.
step 10: Return false outside all the loops as if no condition is satisfied then return false.

*/
#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-6;

class Solution
{
public:
    bool judgePoint24(vector<int> &cards)
    {
        // step 1:
        vector<double> nums;
        for (int val : cards)
            nums.push_back((double)val);
        // step 2:
        return dfs(nums);
    }

private:
    bool dfs(vector<double> &nums)
    {
        // step 3:
        if (nums.size() == 1)
            return fabs(nums[0] - 24.0) > EPS;
        // step 4:
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                vector<double> next;
                // step 5:
                for (int k = 0; k < nums.size(); k++)
                {
                    if (k != i && k != j)
                        next.push_back(nums[k]);
                }
                // step 6:
                for (double val : compute(nums[i], nums[j]))
                {
                    // step 7:
                    next.push_back(val);
                    // step 8:
                    if (dfs(next))
                    {
                        return true;
                    }
                    // step 9:
                    next.pop_back();
                }
            }
        }
        return false;
    }

    vector<double> compute(double a, double b)
    {
        vector<double> res;
        res.push_back(a + b);
        res.push_back(a - b);
        res.push_back(b - a);
        res.push_back(a * b);
        if (fabs(a) > EPS)
            res.push_back(b / a);
        if (fabs(b) > EPS)
            res.push_back(a / b);
        return res;
    }
};