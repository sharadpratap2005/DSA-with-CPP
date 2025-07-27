#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {5, 7, 3, 6, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int second_largest = -1;
    int largest = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            second_largest = largest;
            largest = arr[i];
        }
        else if (arr[i] < largest && second_largest < arr[i])
        {
            second_largest = arr[i];
        }
    }
    cout << "Second Largest element is " << second_largest << endl;

    return 0;
}
/* Another brute force method---> sort the array then apply the loop to find the element just lesser than largest
for (int i = n - 2; i >= 0; i--)
{
    if (arr[i] != arr[n - 1])
    {
        int second_largest = arr[i];
        break;
    }
}*/
