#include <iostream>
using namespace std;

int Maximum_SUM(int arr[], int n)
{
    int sum = 0;
    int max_sum = INT_MIN;
    int start = 0;
    int ansStart = -1;
    int ansEnd = -1;
    for (int i = 0; i < n; i++)
    {

        if (sum == 0)
        {
            start = i;
        }
        sum += arr[i];
        if (sum < 0)
        {
            sum = 0;
        }
        if (sum > 0)
        {
            max_sum = max(sum, max_sum);
            ansStart = start;
            ansEnd = i;
        }
    }
    cout << "Subarray with Maximum Sum: " << endl;
    for (int i = ansStart; i < ansEnd; i++)
    {
        cout << arr[i] << " ";
    }

    // if all the elements are negative.
    if (max_sum < 0)
    {
        max_sum = 0;
    }
    return max_sum;
}
int main()
{
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans = Maximum_SUM(arr, n);
    cout << endl;

    cout << "Sum is " << ans << endl;
    return 0;
}