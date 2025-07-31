// Given the array containing only the binary numbers return the maximnum no of ones that appeared consecutively in an array.
#include <iostream>
using namespace std;
int main()
{
    int arr[] = {1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int count = 0;
    int max_count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            count++;
            max_count = max(max_count, count);
        }
        else if (arr[i] == 0)
        {
            count = 0;
        }
    }
    cout << "Maximum consecutive of ones is " << max_count << endl;
    return 0;
}