class Solution {
public:
//Find the strictly greater power of 2, and subtract 1 from it.
    int smallestNumber(int n) {
        int bits = log2(n) + 1;
        int ans = 1 << bits;
        return ans - 1;
    }
};
