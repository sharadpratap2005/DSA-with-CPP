// BruteFoce --> using linear search time complexity O(n2)

// Optimal Approach --> We will use the mergesort concept in which we just add the count variable to count the possible pairs when the arr[left]>arr[right] and count+=mid-left+1;
/*In merge sorting we divide the array into two halves and then merge these two arrays in an sorted manner*/
#include <bits/stdc++.h>
using namespace std;

int merge_array(vector<int> &arr, int low, int mid, int high)
{
    int count = 0;
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
            count += mid - left + 1;
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

    return count;
}
int merge_sort(vector<int> &arr, int low, int high)
{
    int cnt = 0;
    if (low >= high)
        return cnt;
    int mid = (low + high) / 2;
    cnt += merge_sort(arr, low, mid);
    cnt += merge_sort(arr, mid + 1, high);
    cnt += merge_array(arr, low, mid, high);
    return cnt;
}
int main()
{
    vector<int> arr = {64, 21, 98, 32, 4, 357, 895, 65};
    int n = arr.size();
    cout << merge_sort(arr, 0, n - 1);
    return 0;
}