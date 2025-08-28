class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        unordered_map<int, vector<int>> mpp;

        // fill the map using (i-j)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mpp[i - j].push_back(mat[i][j]);
            }
        }

        // sort the matrix diagonal elements
        for (auto& it : mpp) {

            // upper triangular
            if (it.first < 0) {
                sort(it.second.rbegin(), it.second.rend());
            } else {
                sort(it.second.begin(), it.second.end());
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = mpp[i - j].back();
                mpp[i - j].pop_back();
            }
        }
        return mat;
    }
};
