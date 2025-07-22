#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    int arr[] = {1, 4, 2, 4, 2, 4, 5, 6, 8, 4, 48, 3, 65, 32, 79, 45, 65, 12, 12, 45, 45};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Hash map size should be greater than thhe max element of an arrray

    int max_value = *max_element(arr, arr + n);
    int Hash[max_value + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        Hash[arr[i]]++;
    }

    cout << "Enter the Number to check its frequency: ";
    cin >> num;
    if (num < 0 || num > max_value)
    {
        cout << num << " is out of range in the given array" << endl;
    }
    else
    {

        cout << num << " occurs " << Hash[num] << " times in an array" << endl;
    }

    return 0;
}