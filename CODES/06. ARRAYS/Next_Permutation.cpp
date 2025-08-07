// Find the next lexiographic permutation
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> A = {2, 1, 5, 4, 3, 0, 0};
    int n = A.size();
    int index = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (A[i] < A[i + 1])
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        reverse(A.begin(), A.end());
        return 0;
    }
    for (int i = n - 1; i >= index; i--)
    {
        if (A[i] > A[index])
        {
            swap(A[i], A[index]);
            break;
        }
    }
    reverse(A.begin() + index + 1, A.end());
    for (int i = 0; i < n; i++)
    {
        cout << A[i];
    }

    return 0;
}