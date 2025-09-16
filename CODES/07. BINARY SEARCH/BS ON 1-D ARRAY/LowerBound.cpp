//lowerbound general template
int left = 0;
int right = n - 1;
while (left <= right)
{
    int mid = (left + right) / 2;
    if (arr[mid] >= x)
    {
        ans = mid;
        right = mid - 1;
    }
    else
    {
        low = mid + 1;
    }
}
