class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int max_area = 0;
        int left = 0, right = n - 1;

        while (left <= right) {
            int h = min(height[left], height[right]);
            int w = right - left;

            int temp_area = h * w;
            max_area = max(temp_area, max_area);

            if (height[left] <= height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return max_area;
    }
};
