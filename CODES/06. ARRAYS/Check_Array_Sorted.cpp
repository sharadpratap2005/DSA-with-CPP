#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {1, 2, 2, 3, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            count = 1;
            break;
        }
    }
    if (count == 1)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }

    return 0;
}
