#include <bits/stdc++.h>
using namespace std;

bool f(string &s, int i, int n)
{
    if (i >= n / 2)
        return true;
    if (s[i] != s[n - 1 - i])
        return false;
    return f(s, i + 1, n);
}
int main()
{
    string s;
    cout << "Enter the string: ";
    cin >> s;
    int n = s.length();
    if (f(s, 0, n))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

    return 0;
}