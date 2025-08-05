// Best Time to buy and sell the stock---> it means find the maximum profit that can be possible
#include <iostream>
using namespace std;

int Max_Profit(int arr[], int n)
{
    int max_profit = 0;
    int mini = arr[0];
    for (int i = 1; i < n; i++)
    {
        max_profit = max(max_profit, arr[i] - mini);
        mini = min(mini, arr[i]);
    }
    return max_profit;
}
int main()
{
    int arr[] = {7, 1, 5, 3, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans = Max_Profit(arr, n);
    cout << endl;
    cout << "Maximum Profit is  " << ans << endl;
    return 0;
}