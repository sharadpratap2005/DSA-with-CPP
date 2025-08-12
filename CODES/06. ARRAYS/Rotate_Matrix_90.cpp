#include <bits/stdc++.h>
using namespace std;

// BruteForce Approach--> place element in correct order using another matrix . during conversion matrix_2[j][n-1-1]=matrix_1[i][j]. Time Complexity --> O(n^2) Space complexity --> O(n^n)
void rotate_brute(vector<vector<int>> matrix, int n)
{
    vector<vector<int>> ans(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans[j][n - 1 - i] = matrix[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

// Optimal Approach --->Transpose the matrix and then reverse the each row. Time Complexity ->  O(N*N) + O(N*N)  & Space Complexity -> O(1).
void rotate_better(vector<vector<int>> &matrix, int n)
{
    // Transpose-> every row is converted into column or vice versa.
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    // Reverse the rows
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int n = matrix.size();

    // rotate_brute(matrix, n);
    rotate_better(matrix, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}