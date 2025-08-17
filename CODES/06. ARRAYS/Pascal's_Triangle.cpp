#include <bits/stdc++.h>
using namespace std;

// Given Row and Column find the no at that place.
int find_no(int n, int r)
{
    int res = 1;
    for (int i = 0; i < r; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

// Given the row number print that row of the pascal triangle
void print_row(int n)
{
    int ans = 1;
    cout << ans << " ";
    for (int i = 1; i < n; i++)
    {
        ans *= (n - i);
        ans /= i;
        cout << ans << " ";
    }
}

// print the pascal triangle if the n is given
void print_pascal_triangle(int n)
{
    for (int i = 1; i <= n; i++)
    {
        print_row(i);
        cout << endl;
    }
}

int main()
{
    // findn no
    int row = 5, col = 3;
    cout << find_no(row - 1, col - 1) << endl;

    // print row
    print_row(6);

    // print pascal triangle
    print_pascal_triangle(6);
    return 0;
}