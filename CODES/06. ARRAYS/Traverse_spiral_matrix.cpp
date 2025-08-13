#include <bits/stdc++.h>
using namespace std;

// Time Complexity-> O(n*m) & Space Complexity -> O(n*m).
vector<int> print_spiral_matrix(vector<vector<int>> mat)
{
    int n = mat.size();
    int m = mat[0].size();
    vector<int> ans;

    int top = 0;
    int left = 0;
    int right = m - 1;
    int bottom = n - 1;

    while (top <= bottom && left <= right)
    {
        // left to right
        for (int i = left; i <= right; i++)
        {
            ans.push_back(mat[top][i]);
        }
        top++;
        // top to bottom
        for (int i = top; i <= bottom; i++)
        {
            ans.push_back(mat[i][right]);
        }
        right--;
        // left to right
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                ans.push_back(mat[bottom][i]);
            }
            bottom--;
        }
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(mat[i][left]);
            }
            left++;
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {8, 9, 4}, {7, 6, 5}};
    vector<int> result = print_spiral_matrix(matrix);
    for (int val : result)
    {
        cout << val << " ";
    }
    return 0;
}