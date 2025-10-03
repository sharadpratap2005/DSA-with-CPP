
//BruteForce --> Time Complexity - O(N) & Space Complexity - O(N) 
class Solution {
public:
    vector<int> getLeftMax(vector<int>& height, int n) {
        vector<int> left(n);
        left[0] = height[0];
        for (int i = 1; i < n; i++) {
            left[i] = max(left[i - 1], height[i]);
        }
        return left;
    }
    vector<int> getRightMax(vector<int>& height, int n) {
        vector<int> right(n);
        right[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            right[i] = max(right[i + 1], height[i]);
        }
        return right;
    }
    int trap(vector<int>& height) {
        int ans = 0;
        int n = height.size();

        vector<int> leftMax = getLeftMax(height, n);
        vector<int> rightMax = getRightMax(height, n);

        for (int i = 0; i < n; i++) {
            int h = min(leftMax[i], rightMax[i]) - height[i];
            ans += h;
        }
        return ans;
    }
};
