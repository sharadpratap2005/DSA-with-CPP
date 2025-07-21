#include <bits/stdc++.h>
using namespace std;

/*BruteForce approach--> iterate through 1 to min(n1,n2) using loop
Better approach --> itertate through from min(n1,n2) to 1 in backward loop. if (n1%i==0&&n2%i==0) return i;
*/

// optimal approach----> using euclidean algorithm GCD(a,b) = GCD(a % b,b), a>b
// Euclidean Algorithm --> The GCD is the largest number that divides both integers without leaving a remainder.
int find_GCD(int a, int b)
{
    while (a > 00 && b > 0)
    {
        if (a > b)
        {
            a = a % b;
        }
        else
        {
            b = b % a;
        }
    }
    if (a == 0)
        return b;
    else
        return a;
}
//
int main()
{
    int n1, n2;
    cout << "Enter the first Number: ";
    cin >> n1;
    cout << "Enter the second Number: ";
    cin >> n2;

    int gcd = find_GCD(n1, n2);
    cout << "Greatest common divisor of " << n1 << " and " << n2 << " is " << gcd << endl;

    return 0;
}