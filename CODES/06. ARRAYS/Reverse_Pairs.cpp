#include <bits/stdc++.h>
using namespace std;
void merge_array(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}
int count_pairs(vector<int> &arr, int low, int mid, int high)
{
    int count = 0;
    int right = mid + 1;
    for (int i = low; i <= mid; i++)
    {
        while (right <= high && arr[i] > 2 * arr[right])
        {
            right++;
        }
        count += (right - (mid + 1));
    }
    return count;
}
int merge_sort(vector<int> &arr, int low, int high)
{
    int count = 0;
    if (low >= high)
        return count;

    int mid = (low + high) / 2;

    count += merge_sort(arr, low, mid);        // left part
    count += merge_sort(arr, mid + 1, high);   // right part
    count += count_pairs(arr, low, mid, high); // count the pairs
    merge_array(arr, low, mid, high);
    return count;
}

int main()
{
    vector<int> arr = {4, 1, 2, 3, 1};
    int n = arr.size();
    cout << merge_sort(arr, 0, n - 1);
    return 0;
}