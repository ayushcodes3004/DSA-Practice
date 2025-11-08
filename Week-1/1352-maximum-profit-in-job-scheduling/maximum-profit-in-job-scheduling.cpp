class Solution {
private:
     // Binary search for the next job with start >= current end
    int findNext(int i,int n,vector<vector<int>>& arr){
        int l=i+1;
        int r=n-1;
        int ans=n;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(arr[mid][0]>=arr[i][1]){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
    int rec(int i,int n,vector<vector<int>>& arr,vector<int>& dp){
        if(i==n)    return 0;
        if(dp[i]!=-1)   return dp[i];
        int leave=rec(i+1,n,arr,dp);
        int profit=arr[i][2];
        int next=findNext(i,n,arr);
        int take=profit+rec(next,n,arr,dp);
        return dp[i]=max(take,leave);
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        vector<vector<int>>arr(n,vector<int>(3));
        for(int i=0;i<n;i++){
            arr[i][0] = startTime[i];
            arr[i][1] = endTime[i];
            arr[i][2] = profit[i];
        }
        sort(arr.begin(),arr.end());
        vector<int>dp(n,-1);
        return rec(0,n,arr,dp);
    }
};