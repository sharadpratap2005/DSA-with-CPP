class Solution {
public:
    bool isPerfectSquare(long long n) {
        long long r = sqrt(n);
        return r * r == n;
    }
    int countTriples(int n) {
        int count = 0;
        for (int i = 1; i <= n; i++) {
            int a = i * i;
            for (int j = 1; j <= n; j++) {
                int b = j * j;
                long long c = a + b;
                if (isPerfectSquare(c) && sqrt(c) <= n)
                    count++;
            }
        }
        return count;
    }
};
