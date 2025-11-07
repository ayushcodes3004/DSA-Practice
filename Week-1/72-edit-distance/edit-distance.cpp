class Solution {
private:
    int rec(int i,int j,string& word1, string& word2,vector<vector<int>>& dp){
        if(i==word1.size())    return word2.size()-j;
        if(j==word2.size())    return word1.size()-i;

        if(dp[i][j]!=-1)    return dp[i][j];

        int ans=0;
        if(word1[i]==word2[j])  ans=rec(i+1,j+1,word1,word2,dp);
        else    ans=1+min({rec(i,j+1,word1,word2,dp),rec(i+1,j,word1,word2,dp),rec(i+1,j+1,word1,word2,dp)});

        return dp[i][j]=ans;
    }
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        // return rec(0,0,word1,word2,dp);
        //base case
        for(int i = 0; i <= n; i++) dp[i][0] = i;  // all deletions
        for(int j = 0; j <= m; j++) dp[0][j] = j;  // all insertions
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1])  dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=1+min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]});
            }
        }
        return dp[n][m];
    }
};