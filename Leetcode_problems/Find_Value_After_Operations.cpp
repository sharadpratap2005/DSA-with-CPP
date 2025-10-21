class Solution {
public:
    int finalValueAfterOperations(vector<string>& s) {
        int n = s.size();
        int x = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == "--X" || s[i] == "X--") {
                x--;
            } else {
                x++;
            }
        }
        return x;
    }
};
