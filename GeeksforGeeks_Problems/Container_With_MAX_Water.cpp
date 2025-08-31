class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int n=arr.size();
        int left=0;
        int right=n-1;
        int max_area=0;
        while(left<right){
            int height=min(arr[left],arr[right]);
            int width=right-left;
            int temp_area=height*width;
                max_area=max(temp_area,max_area);
            if(arr[left]<arr[right]){
                left++;
            }
            else {
               right--;
        }
        
        }
        return max_area;
        
    }
};
