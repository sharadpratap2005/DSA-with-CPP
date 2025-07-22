#include <bits/stdc++.h>
using namespace std;

int main()
{
    char ch;
    char c;
    string s;
    cout << "Enter the string: ";
    cin >> s;

    int Hash[256] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        Hash[s[i]]++;
    }

    cout << "Enter the character to check its frequency: ";
    cin >> ch;

    cout << ch << " occurs " << Hash[ch] << " times" << endl;

    return 0;
}