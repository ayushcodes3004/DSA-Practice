class Solution {
private:
    int rec(int i,int j,int m,int n,vector<vector<int>>& grid,vector<vector<int>>& dp){
        // if(i==m || j==n)    return 0;
        if(i==m-1 && j==n-1)    return grid[i][j];
        if(dp[i][j]!=-1)    return dp[i][j];
        int down=INT_MAX;
        int right=INT_MAX;
        int ans=INT_MAX;
        if(i+1<m){
            down= grid[i][j]+  rec(i+1,j,m,n,grid,dp);
            ans=min(ans,down);
        }   
        if(j+1<n){
            right=grid[i][j]+ rec(i,j+1,m,n,grid,dp);
            ans=min(ans,right);
        }   
        return dp[i][j]=ans;
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,INT_MAX));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(i==1 && j==1)    dp[i][j]=grid[i-1][j-1];
                else{
                    dp[i][j]=grid[i-1][j-1]+min(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};