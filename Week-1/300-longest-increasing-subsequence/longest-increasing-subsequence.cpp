class Solution {
private:
    int rec(int i,int j,vector<int>& nums,int n,vector<vector<int>>& dp){
        if(i>=n)  return 0;
        int ans=0;
        if(dp[i][j+1]!=-1)   return dp[i][j+1];

        int leave=rec(i+1,j,nums,n,dp);
        ans=max(ans,leave);
        if(j==-1|| nums[i]>nums[j]){
            int take=1+rec(i+1,i,nums,n,dp);
            ans=max(ans,take);
        }
        return dp[i][j+1]=ans;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return rec(0,-1,nums,n,dp);
    }
};