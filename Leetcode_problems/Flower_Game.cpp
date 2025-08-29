//Alice and Bob playing flower game

//BruteForce --> We will generate all possible pairs and check their limit and check if the sum is odd then count++. T.C O(n2) & S.C O(n2)
class Solution {
public:
    long long flowerGame(int n, int m) {
        long long count = 0;
        vector<pair<int, int>> p;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (i != j) {
                    p.push_back({i, j});
                }
            }
        }

        for (auto it : p) {
            if (it.first <= n && it.second <= m) {
                int c = it.first + it.second;
                if (c % 2 != 0) {
                    count++;
                }
            }
        }
        return count;
    }
};

//Optiaml Solution--> Just find the no of ways in which one number is odd and one number is even so that the sum is odd and alice wins.

class Solution {
public:
    long long flowerGame(int n, int m) {
        long long nEven = n / 2;
        long long nOdd = (n + 1) / 2;
        long long mEven = m / 2;
        long long mOdd = (m + 1) / 2;

        return (nEven * mOdd) + (nOdd * mEven);
    }
};