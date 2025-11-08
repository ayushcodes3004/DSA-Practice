class Solution {
private:
    int rec(int i,int j,vector<int>& cuts,vector<vector<int>>& dp){
        if(j==i+1)  return 0;
        if(dp[i][j]!=-1)    return dp[i][j];
        int cost=cuts[j]-cuts[i];
        int ans=INT_MAX;
        for(int k=i+1;k<j;k++){
            int curr=rec(i,k,cuts,dp)+rec(k,j,cuts,dp)+cost;
            ans=min(ans,curr);
        }
        return dp[i][j]=ans;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int c=cuts.size();
        vector<vector<int>>dp(c,vector<int>(c,-1));
        return rec(0,c-1,cuts,dp);
    }
};