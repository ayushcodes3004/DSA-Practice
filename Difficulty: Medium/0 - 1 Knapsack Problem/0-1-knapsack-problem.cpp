class Solution {
  private:
    int rec(int i,int j,vector<int> &val, vector<int> &wt,vector<vector<int>>& dp){
        int n=val.size();
        if(i==n)    return 0;
        if(dp[i][j]!=-1)    return dp[i][j];
        
        int leave=rec(i+1,j,val,wt,dp);
        if(j<wt[i]) return leave;
        int take=val[i]+rec(i+1,j-wt[i],val,wt,dp);
        return dp[i][j]=max(take,leave);
    }
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=val.size();
        vector<vector<int>>dp(n,vector<int>(W+1,-1));
        return rec(0,W,val,wt,dp);
    }
};