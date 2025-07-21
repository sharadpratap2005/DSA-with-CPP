#include <bits/stdc++.h>
using namespace std;

bool armstrong_no(int n)
{
    int original_no = n;
    int count = (int)(log10(n) + 1);
    int sum = 0;
    while (n > 0)
    {
        int last_digit = n % 10;
        sum += pow(last_digit, count);
        n /= 10;
    }
    if (original_no == sum)
        return true;
    else
        return false;
}
int main()
{
    int n;
    cout << "Enter the Number: ";
    cin >> n;
    if (armstrong_no(n))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    return 0;
}