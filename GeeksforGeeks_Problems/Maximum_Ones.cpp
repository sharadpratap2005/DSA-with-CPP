class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        int n = arr.size();
        int countzero=0;
        int len=0;
        int left=0,right=0;
        
        while(right<n){
            //count zero
            if(arr[right]==0)countzero++;
            
            //shrink the window if zero exceeds k 
            while(countzero>k){
                if(arr[left]==0){
                    countzero--;
                }
                    left++;
            }
            
            len=max(len,right-left+1);
            right++;
        }
        return len;
        
        
    }
};
