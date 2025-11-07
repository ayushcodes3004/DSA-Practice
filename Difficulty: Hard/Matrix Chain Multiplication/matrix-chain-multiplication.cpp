class Solution {
  private:
    int rec(int i,int j,vector<int> &arr,vector<vector<int>>& dp){
        if(i+1==j)  return 0;
        int ans=INT_MAX;
        if(dp[i][j]!=-1)    return dp[i][j];
        for(int k=i+1;k<j;k++){
            int op=rec(i,k,arr,dp)+rec(k,j,arr,dp)+arr[i]*arr[j]*arr[k];
            ans=min(op,ans);
        }
        return dp[i][j]=ans;
    }
  public:
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n=arr.size();
        int i=0;
        int j=n-1;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return rec(i,j,arr,dp);
    }
};