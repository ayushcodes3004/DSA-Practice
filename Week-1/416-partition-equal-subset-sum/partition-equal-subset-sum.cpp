class Solution {
private:
    bool rec(int i,int j,int n,vector<int>& nums,vector<vector<int>>& dp){
        if(j==0)    return true;
        if(j<0 || i>=n) return false;
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
        vector<vector<bool>>dp(n+1,vector<bool>(1+target,false));
        for(int i=0;i<=n;i++)   dp[i][0]=true;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){
                int leave=dp[i-1][j];
                int take=0;
                if(j>=nums[i-1]){
                    take=dp[i-1][j-nums[i-1]];
                }
                dp[i][j]=(take||leave);
            }
        }
        return dp[n][target];
    }
};