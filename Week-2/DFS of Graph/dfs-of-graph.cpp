class Solution {
  private:
    void dfsHelper(int node,vector<vector<int>>& adj,vector<bool>& vis,vector<int>& ans){
        vis[node]=true;
        ans.push_back(node);
        for(int neigh: adj[node]){
            if(!vis[neigh]){
                // vis[neigh]=true;
                dfsHelper(neigh,adj,vis,ans);
            }
        }
    }
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n=adj.size();
        vector<int>ans;
        vector<bool>vis(n,false);
        dfsHelper(0,adj,vis,ans);
        return ans;
    }
};