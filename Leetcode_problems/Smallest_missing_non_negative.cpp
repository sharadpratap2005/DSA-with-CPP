/* We find the remainder of every element by value as we recquire the positive no therefore using arithmetic modulo concept . store the elements in unordered map with their frequency. as long as there is a mex % value present in map . increase the mex and finaly return the mex */
class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int mex = 0;
        unordered_map<int, int> mpp;
        for (int& val : nums) {
            int r = ((val % value) + value) % value;
            mpp[r]++;
        }
        while (mpp[(mex % value)] > 0) {
            mpp[(mex % value)]--;
            mex++;
        }
        return mex;
    }
};
