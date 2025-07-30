// Intersection of two sorted arrays using two pointer approach
#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> intersection_array;
    int arr_1[] = {1, 1, 2, 2, 3, 5, 5, 5, 5, 6, 7, 7};
    int arr_2[] = {1, 2, 2, 2, 3, 3, 4, 6, 7, 7};
    int n1 = sizeof(arr_1) / sizeof(arr_1[0]);
    int n2 = sizeof(arr_2) / sizeof(arr_2[0]);

    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (arr_1[i] < arr_2[j])
        {
            i++;
        }
        else if (arr_1[i] > arr_2[j])
        {
            j++;
        }
        else
        {
            intersection_array.push_back(arr_1[i]);
            i++;
            j++;
        }
    }

    for (int val : intersection_array)
    {
        cout << val << " ";
    }
    return 0;
}
