#include <bits/stdc++.h>
using namespace std;

// BruteForce Approach---> set the non zero element to -1 of rows and column in which zero appeared and then iterate through matrix again to set the -1 to 0
void markRow(int i, int m, int matrix[][4])
{
    for (int j = 0; j < m; j++)
    {
        if (matrix[i][j] != 0)
        {
            matrix[i][j] = -1;
        }
    }
}
void markColumn(int j, int n, int matrix[][4])
{
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][j] != 0)
        {
            matrix[i][j] = -1;
        }
    }
}
void brute_matrix(int matrix[][4], int n, int m)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                markRow(i, m, matrix);
                markColumn(j, n, matrix);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == -1)
            {
                matrix[i][j] = 0;
            }
        }
    }
}

// Better Approach---> track the rows and column which should become equal to zero.
void better_matrix(int matrix[][4], int n, int m)
{
    int rows[n] = {0};
    int columns[m] = {0};

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {

            if (matrix[i][j] == 0)
            {
                rows[i] = 1;
                columns[j] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {

            if (rows[i] || columns[j])
            {
                matrix[i][j] = 0;
            }
        }
    }
}

// Optimal Approach ---->
void optimal_matrix(int matrix[][4], int n, int m)
{
    int x = 1, y = 1;
    // check for zero in 0th row
    for (int i = 0; i < m; i++)
    {
        if (matrix[0][i] == 0)
        {
            x = 0;
        }
    }
    // check for zero in 0th column
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][0] == 0)
        {
            y = 0;
        }
    }
    // check for zero in (n-1)*(m-1) matrix and mark it
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }
    // change the elements to zero of columns if there is mark present
    for (int col = 1; col < m; col++)
    {
        if (matrix[0][col] == 0)
        {
            for (int row = 0; row < n; row++)
            {
                matrix[row][col] = 0;
            }
        }
    }
    // change the elements to zero of rows if there is mark present
    for (int row = 1; row < n; row++)
    {
        if (matrix[row][0] == 0)
        {
            for (int col = 0; col < m; col++)
            {
                matrix[row][col] = 0;
            }
        }
    }
    // change the 0th row to zero if x=0
    if (x == 0)
    {
        for (int i = 0; i < m; i++)
        {
            matrix[0][i] = 0;
        }
    }
    // change the 0th column to zero if y=0
    if (y == 0)
    {
        for (int i = 0; i < n; i++)
        {
            matrix[i][0] = 0;
        }
    }
}

// Display the matrix
void display_matrix(int matrix[][4], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int matrix[3][4] = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    int n = 3;
    int m = 4;
    // brute_matrix(matrix, n, m);
    // better_matrix(matrix, n, m);
    optimal_matrix(matrix, n, m);
    display_matrix(matrix, n, m);
    return 0;
}