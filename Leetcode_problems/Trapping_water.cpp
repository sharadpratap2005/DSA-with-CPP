
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

//Optimal Approach --> Time Complexity - O(N) & Space Complexity - O(1)
// Use two pointers approach first we find the minimum of height[left] and height[right] using if else. Then we check if the height[left] or height[right] is greater than the leftMax and rightMax respectively then assign them the maxium values else add the value to the answer by leftMax - height[left] or rightMax - height[right].

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;
        int ans = 0;

        while (left <= right) {
            if (height[left] <= height[right]) {
                if (height[left] >= leftMax)
                    leftMax = height[left];
                else
                    ans += leftMax - height[left];
                left++;

            } else {
                if (height[right] >= rightMax)
                    rightMax = height[right];
                else
                    ans += rightMax - height[right];
                right--;
            }
        }
        return ans;
    }
};
