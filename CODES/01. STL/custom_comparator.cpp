/*create a custom comparator in which sort the pair according to the second element , if second element is same then sort according to first element but in descending order. */
#include <bits/stdc++.h>
using namespace std;
bool custom_comparator(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.second < p2.second)
        return true;
    if (p1.second > p2.second)
        return false;
    if (p1.first > p2.first)
        return true;
    return false;
}
//sort the array elements according to their frequency 
auto comp=[&](const int& a, int& b){
            if(freq[a] != freq[b]){
                return freq[a]<freq[b];
            }
            return a>b;
        };
        sort(nums.begin(), nums.end(), comp);
int main()
{
    pair<int, int> p[] = {{1, 2}, {3, 6}, {4, 3}, {6, 4}, {8, 6}, {2, 6}};
    int n = sizeof(p) / sizeof(p[0]);
    sort(p, p + n, custom_comparator);
    for (auto it : p)
    {
        cout << it.first << " , " << it.second << endl;
    }
    return 0;

}
