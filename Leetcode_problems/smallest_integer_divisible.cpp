class Solution {
public:
//in this problem we store the modulo to get the next modulo for next original number ...without storing the original number. length lies between 1 to k-1 only.
    int smallestRepunitDivByK(int k) {
        int num = 0;
        for (int length = 1; length <= k; length++) {
            num = (num * 10 + 1) % k;
            if(num==0)
            return length;
        }
        return -1;
    }
};
