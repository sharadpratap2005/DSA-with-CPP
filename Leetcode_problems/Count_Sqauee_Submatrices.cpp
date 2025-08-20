class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        // create a matirx dp to store of same size of given the martrix
        vector<vector<int>> dp(n, vector<int>(m, 0));

        // store the first row and firts column as it is in matrix
        for (int i = 0; i < n; i++)
            dp[i][0] = matrix[i][0];
        for (int j = 0; j < m; j++)
            dp[0][j] = matrix[0][j];

        // now check the minium of previous ,above and diagonal element minuimun
        // add add it to 1 if the right bottom place is equal to one else put 0
        // there
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == 0) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] =
                        min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1])) +
                        1;
                }
            }
        }
        //calculate the sum of the dp array as it will have no of submatrices
        int sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sum += dp[i][j];
            }
        }
        return sum;
    }
};
