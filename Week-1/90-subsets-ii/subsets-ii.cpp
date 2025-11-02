class Solution {
private:
    void rec(int i,vector<vector<int>>& ans,vector<int>& res,vector<int>& nums){
        int n=nums.size();
        if(i==n){
            ans.push_back(res);
            return;
        }
        res.push_back(nums[i]);
        rec(i+1,ans,res,nums);

        res.pop_back();
        i=i+1;
        while(i<n && nums[i-1]==nums[i]) i++;
        rec(i,ans,res,nums);
        
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>res;
        rec(0,ans,res,nums);
        return ans;
    }
};