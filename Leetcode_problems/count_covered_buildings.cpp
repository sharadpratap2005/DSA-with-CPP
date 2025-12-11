//Bruteforce method 
class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int count = 0;
        int size = buildings.size();
        if (size < 5)
            return 0;

        for (int i = 0; i < size; i++) {
            int curr_x = buildings[i][0];
            int curr_y = buildings[i][1];
            bool r = false, l = false, u = false, d = false;

            for (int j = 0; j < size; j++) {
                if (j != i) {
                    // if y (height) is equal
                    if (buildings[j][1] == curr_y) {
                        // check for right
                        if (buildings[j][0] > curr_x)
                            r = true;
                        // check for left
                        if (buildings[j][0] < curr_x)
                            l = true;

                    }
                    // if x (width) is equal
                    else if (buildings[j][0] == curr_x) {
                        // check for up
                        if (buildings[j][1] > curr_y)
                            u = true;
                        if (buildings[j][1] < curr_y)
                            d = true;
                    }
                }
            }
            if (r && l && u && d) {
                count++;
            }
        }
        return count;
    }
};
