// BruteForce--> O(n)
class Solution
{
public:
    int findKthPositive(vector<int> &nums, int k)
    {
        int n = nums.size();
        int num = 1;
        int i = 0;
        while (i < n && k > 0)
        {
            if (nums[i] == num)
            {
                i++;
            }
            else
            {
                k--;
            }
            num++;
        }
        while (k--)
        {
            num++;
        }
        return num - 1;
    }
};

// Optimal using Binary search logn

class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int n = arr.size();
        int low = 0;
        int high = n - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            int missing = arr[mid] - (mid + 1);

            if (missing < k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low + k;
    }
};