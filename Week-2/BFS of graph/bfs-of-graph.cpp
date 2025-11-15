class Solution {
  private:
    void bfsHelper(int i,vector<vector<int>> &adj,vector<bool>& vis,vector<int>& ans){
        queue<int>q;
        q.push(i);
        vis[i]=true;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(int neigh: adj[node]){
                if(!vis[neigh]){
                    q.push(neigh);
                vis[neigh]=true;
                }
                
            }
        }
    }
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int n=adj.size();
        vector<int>ans;
        vector<bool>vis(n,false);
        bfsHelper(0,adj,vis,ans);
        return ans;
    }
};