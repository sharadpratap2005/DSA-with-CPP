#include <bits/stdc++.h>
using namespace std;

int count_subarrays_with_sum_k(vector<int> arr, int k)
{
    unordered_map<int, int> mpp;
    mpp[0] = 1;
    int preSum = 0;
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        preSum += arr[i];
        int remove = preSum - k;
        count += mpp[remove];
        mpp[preSum]++;
    }
    return count;
}
int main()
{
    vector<int> arr = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
    cout << count_subarrays_with_sum_k(arr, 3);
    return 0;
}