class Solution {
private:
    int rec(int i,int amt,vector<int>& coins, int n,vector<vector<int>>&dp){
        if(amt==0)  return 0;
        if(amt<0)   return 1e9;
        int ans=INT_MAX;
        if(i==n)    return ans;
        if(dp[i][amt]!=-1)    return dp[i][amt];
        int leave=rec(i+1,amt,coins,n,dp);
        ans=min(ans,leave);
        int take=1+rec(i,amt-coins[i],coins,n,dp);
        ans=min(ans,take);
        return dp[i][amt] =ans;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans= rec(0,amount,coins,n,dp);
        return (ans>=1e9)?-1:ans;
    }
};