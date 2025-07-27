#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {1, 1, 2, 2, 3, 3, 3, 5, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i = 0;
    for (int j = 1; j < n; j++)
    {
        if (arr[i] != arr[j])
        {
            i++;
            arr[i] = arr[j];
        }
    }
    cout << "No of unique elements is " << i + 1 << endl;
    for (int k = 0; k <= i; k++)
    {
        cout << arr[k] << " ";
    }

    return 0;
}