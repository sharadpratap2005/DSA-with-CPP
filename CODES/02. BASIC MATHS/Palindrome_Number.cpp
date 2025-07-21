#include <bits/stdc++.h>
using namespace std;

// palindrome no --> if reverse == original
int palindrome_check(int n)
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
    if (n == palindrome_check(n))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}