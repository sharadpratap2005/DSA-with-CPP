#include <bits/stdc++.h>
using namespace std;

int count_subarrays_with_XOR_k(vector<int> arr, int k)
{
    unordered_map<int, int> mpp;
    mpp[0] = 1;
    int XOR = 0;
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        XOR = XOR ^ arr[i];
        int x = XOR ^ k;
        count += mpp[x];
        mpp[XOR]++;
    }
    return count;
}
int main()
{
    vector<int> arr = {4, 2, 2, 6, 4};
    cout << count_subarrays_with_XOR_k(arr, 6);
    return 0;
}