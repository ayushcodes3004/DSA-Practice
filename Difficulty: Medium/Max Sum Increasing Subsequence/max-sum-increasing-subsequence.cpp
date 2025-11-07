class Solution {
  public:
    int maxSumIS(vector<int>& arr) {
        // Your code goes here
        int n=arr.size();
        vector<int>dp(n);
        for(int i=0;i<n;i++)   dp[i]=arr[i];
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[i]>arr[j]) dp[i]=max(dp[i],arr[i]+dp[j]);
            }
        }
        int maxi=dp[0];
        for(int el: dp) maxi=max(maxi,el);
        return maxi;
    }
};