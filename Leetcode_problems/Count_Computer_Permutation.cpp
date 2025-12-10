class Solution {
public:
    int M = 1e9 + 7;
    long long factorial(int num) {
        long long f = 1;
        for (int i = 1; i <= num; i++) {
            f = (f * i) % M;
        }
        return f;
    }
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        int ans = 0;
        int mini = *min_element(complexity.begin(), complexity.end());
        if (complexity[0] > mini)
            return 0;
        int count = 0;
        for (int val : complexity) {
            if (val == mini)
                count++;
            if (count == 2)
                return 0;
        }
        ans = factorial(n - 1);
        return ans;
    }
};



class Solution {
public:
    int M = 1e9 + 7;
    int countPermutations(vector<int>& complexity) {
        long long ans = 1;
        int n = complexity.size();

        for (int i = 1; i < n; i++) {
            if (complexity[i] <= complexity[0])
                return 0;

            ans = (ans * i) % M;
        }
        return ans;
    }
};
