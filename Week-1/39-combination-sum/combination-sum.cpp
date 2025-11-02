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
        solve(arr,target-arr[i],res,i,ans);
        res.pop_back();
        solve(arr,target,res,i+1,ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>res;
        solve(candidates,target,res,0,ans);
        return ans;
    }
};