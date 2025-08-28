#include <bits/stdc++.h>
using namespace std;

// BruteForce--> Store the element of array1 and array 2 in another array having size m+n using two pointer approach.
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> nums3;
        int left = 0, right = 0, index = 0;
        while (left <= m && right <= n)
        {
            if (nums1[left] <= nums2[right])
            {
                nums3[index] = nums1[left];
                left++;
                index++;
            }
            else
            {
                nums3[index] = nums2[right];
                right++;
                index++;
            }
        }
        while (left < m)
        {
            nums3[index++] = nums2[left++];
        }
        while (right < n)
        {
            nums3[index++] = nums2[right++];
        }

        for (int i = 0; i < m + n; i++)
        {
            if (i < m)
            {
                nums1[i] = nums3[i];
            }
            else
            {
                nums2[i - n] = nums3[i];
            }
        }
    }
};

// Optimal 1 solution-> compare if largest element and smallest element of the array 1 and array 2 respectively and swap them if not break;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int left = m - 1, right = 0;
        while (left >= 0 && right < n)
        {
            if (nums1[left] > nums2[right])
            {
                swap(nums1[left], nums2[right]);
                left--;
                right++;
            }
            else
            {
                break;
            }
        }
        sort(nums1.begin(), nums1.begin() + m);
        sort(nums1.begin(), nums1.begin() + m);
    }
};