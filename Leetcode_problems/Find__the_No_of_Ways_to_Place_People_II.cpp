class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int result = 0;
        int n = points.size();

        // custom comparator to sort
        auto lambda = [](vector<int>& p1, vector<int>& p2) {
            if (p1[0] == p2[0])
                return p1[1] > p2[1];
            return p1[0] < p2[0];
        };

        // sort
        sort(points.begin(), points.end(), lambda);

        for (int i = 0; i < n; i++) {
            // A - point for Alice (x1,y1)
            int x1 = points[i][0];
            int y1 = points[i][1];

            int max_y = INT_MIN;
            for (int j = i + 1; j < n; j++) {
                // B -point for Bob (x2,y2)
                int x2 = points[j][0];
                int y2 = points[j][1];
                if (y2 > y1)
                    continue;
                if (y2 > max_y) {
                    result++;
                    max_y = y2;
                }
            }
        }

        return result;
    }
};
