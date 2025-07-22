#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {51, 23, 45, 1, 1, 1, 23, 2, 95, 6, 23, 3};
    unordered_map<int, int> freq;
    for (auto it : arr)
    {
        freq[it]++;
    }
    cout << "No | frequency" << endl;
    for (auto it : freq)
    {
        cout << it.first << " , " << it.second << endl;
    }
}