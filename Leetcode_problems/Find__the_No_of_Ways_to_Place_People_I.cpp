//My code Brute force but does not pass all the testcases
class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            // let it be A=(x1,y1)
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = 0; j < n; j++) {
                // let it be B=(x2,y2)
                if (i != j) {
                    int x2 = points[j][0];
                    int y2 = points[j][1];
                    // for A (x1,y1) and B(x2,y2) to form the pair check the
                    // condtion
                    // first condition to check if  a is at upper left side of b
                    if (x1 < x2 && y1 > y2) {
                        bool valid = true;
                        // if a is at upper left side of b
                        // now
                        // check second condition that ther is no any other
                        // point on the line forming by a and b or the rectangle
                        // formed by a and b to check this condition
                        for (int k = 0; k < n; k++) {
                            if (k != i && k != j) {
                                int x3 = points[k][0];
                                int y3 = points[k][1];

                                if (x1 <= x3 && x3 <= x2 && y2 <= y3 &&
                                    y3 <= y1) {
                                    valid = false;
                                    break;
                                }
                            }
                        }
                        if (valid)
                            count++;
                    }
                }
            }
        }
        return count;
    }
};
