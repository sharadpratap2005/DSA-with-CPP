class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        int n=arr.size();
        if(n==0)return 0;
        sort(arr.begin(),arr.end());
        int ans = arr[n-1]-arr[0];//intitial differnence
        int smallest = arr[0]+k;
        int largest = arr[n-1]-k;
      
        
        for(int i=0;i<n-1;i++){
            int min_height=min(smallest,arr[i+1]-k);
            int max_height=max(largest,arr[i]+k);
            if(min_height<0)continue;
            ans=min(ans,max_height-min_height);
}
        return ans;
    }
};
