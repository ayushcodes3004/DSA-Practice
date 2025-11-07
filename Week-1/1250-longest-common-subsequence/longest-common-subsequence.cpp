class Solution {
private:
    int rec(int i,int j,string s1, string s2, vector<vector<int>>& dp){
        if(i>=s1.size()|| j>=s2.size()) return 0;
        int ans=0;
        if(dp[i][j]!=-1)    return dp[i][j];
        if(s1[i]==s2[j])    ans=1+rec(i+1,j+1,s1,s2,dp);
        else ans=max(rec(i+1,j,s1,s2,dp),rec(i,j+1,s1,s2,dp));
        return dp[i][j]=ans;
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();

        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        // return rec(0,0,text1,text2,dp);
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(text1[i-1]==text2[j-1])  dp[i][j]=1+dp[i-1][j-1];
                else    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n1][n2];
        
    }
};