class Solution {
private:
    void solve(vector<int>& arr, int target,vector<int>res,int i,vector<vector<int>>& ans){
        int n=arr.size();
        if(i==n){
            if(target==0)   ans.push_back(res);
            return;
        }
        if(target<0)    return;
        res.push_back(arr[i]);
        solve(arr,target-arr[i],res,i+1,ans);
        res.pop_back();
        i=i+1;
        while(i<n && arr[i-1]==arr[i])  i++;
        solve(arr,target,res,i,ans);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int>ds;
        solve(candidates,target,ds,0,ans);
        return ans;
    }
};