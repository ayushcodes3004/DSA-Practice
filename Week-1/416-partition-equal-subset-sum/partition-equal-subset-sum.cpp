class Solution {
private:
    bool rec(int i,int j,int n,vector<int>& nums,vector<vector<int>>& dp){
        if(j==0)    return true;
        if(j<0 || i==n) return false;
        if(dp[i][j]!=-1)    return dp[i][j];
        int take= rec(i+1,j-nums[i],n,nums,dp);
        int leave=rec(i+1,j,n,nums,dp);
        return dp[i][j]=(take+leave);
    }
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int num: nums)  sum+=num;
        if(sum%2)   return false;
        int target=sum/2;
        vector<vector<int>>dp(n,vector<int>(1+target,-1));
        return rec(0,target,n,nums,dp);
    }
};