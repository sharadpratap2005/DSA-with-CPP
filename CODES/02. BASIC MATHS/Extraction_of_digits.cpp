#include <bits/stdc++.h>
using namespace std;

int count_digit(int n)
{
    int count = 0;
    while (n > 0)
    {
        count++;
        int last_digit = n % 10;
        n /= 10;
    }
    // int count = (int)(log10(n)+1);---> another direct way to count the no of digits.
    return count;
}
int main()
{
    int n;
    cout << "Enter the Number: ";
    cin >> n;
    cout << count_digit(n);
    return 0;
}