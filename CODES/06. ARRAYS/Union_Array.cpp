//Union Array of two sorted arrays using two pointer approach 
#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> union_array;
    int arr_1[] = {1, 1, 2, 2, 3, 5, 5, 5, 5, 6, 7, 7};
    int arr_2[] = {1, 2, 2, 2, 3, 3, 4, 6, 7, 7};
    int n1 = sizeof(arr_1) / sizeof(arr_1[0]);
    int n2 = sizeof(arr_2) / sizeof(arr_2[0]);

    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (arr_1[i] <= arr_2[j])
        {
            if (union_array.size() == 0 || union_array.back() != arr_1[i])
            {
                union_array.push_back(arr_1[i]);
            }
            i++;
        }
        else
        {
            if (union_array.size() == 0 || union_array.back() != arr_2[j])
            {
                union_array.push_back(arr_2[j]);
            }
            j++;
        }
    }
    while (i < n1)
    {
        if (union_array.size() == 0 || union_array.back() != arr_1[i])
        {
            union_array.push_back(arr_1[i]);
        }
        i++;
    }
    while (j < n2)
    {
        if (union_array.size() == 0 || union_array.back() != arr_2[j])
        {
            union_array.push_back(arr_2[j]);
        }
        j++;
    }
    for (int val : union_array)
    {
        cout << val << " ";
    }
    return 0;
}
/*Another Brute Force Method--> Iterate through each element from both the array and store it in set.*/