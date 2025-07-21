#include <bits/stdc++.h>
using namespace std;

int fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}
int main()
{
    int n;
    cout << "Enter the Number: ";
    cin >> n;

    cout << fibonacci(n);
    return 0;
}
/*another method
if(n<=1) return n;
int a=0,b=1,c;
for(int i=2;i<=n;i++){
c=a+b;
b=c;
a=b;
}
return c;
*/
