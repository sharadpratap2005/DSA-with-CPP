#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {5, 7, 3, 6, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int largest = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }
    cout << "Largest element of an array: " << largest << endl;

    return 0;
}
//Another brute force method----> sort the array and last element will be the largest element T.C o(nlogn)