#include <bits/stdc++.h>
using namespace std;

int reverse_no(int n)
{
    int rev_no = 0;
    while (n > 0)
    {
        int last_digit = n % 10;
        rev_no = rev_no * 10 + last_digit;
        n /= 10;
    }
    return rev_no;
}
int main()
{
    int n;
    cout << "Enter the Number: ";
    cin >> n;
    cout << reverse_no(n);
    return 0;
}