#include <bits/stdc++.h>
using namespace std;

void print_name(int i, int n)
{
    if (i > n)
    {
        return;
    }
    cout << "Sharad Pratap" << endl;
    print_name(i + 1, n);
}
int main()
{
    int n;
    cout << "Enter the Number: ";
    cin >> n;
    print_name(1, n);
    return 0;
}