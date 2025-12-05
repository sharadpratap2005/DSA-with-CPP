class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0); // total sum
        int left_sum = 0;                                  // left sum
        int right_sum = 0;                                 // right sum
        int ans = 0; // count the partitions

        // iterate through the array till n-2 and find the possible pairs
        for (int i = 0; i < n - 1; i++) {
            left_sum += nums[i];
            right_sum = sum - left_sum;
            if ((left_sum - right_sum) % 2 == 0)
                ans++;
        }
        return ans;
    }

};

/*we can do it in single pass only as the number of partitions will depend on the nature of total sum. if the sum is even it will have n-1 all partitions as valid partitions otherwise it will have zero partitions. */
class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int val : nums) {
            sum += val;
        }
        return (sum % 2 == 0) ? n - 1 : 0;
    }
};
