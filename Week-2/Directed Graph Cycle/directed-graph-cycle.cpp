class Solution {
  private:
    bool dfs(int node,vector<vector<int>> &adj,vector<bool>& vis, vector<bool>& dfsVis){
        vis[node]=true;
        dfsVis[node]=true;
        for(int neigh: adj[node]){
            if(!vis[neigh]){
                if(dfs(neigh,adj,vis,dfsVis)) return true;
            }else if(dfsVis[neigh])  return true;
        }
        dfsVis[node]=false;
        return false;
    }
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            // adj[v].push_back(u);
        }
        vector<bool> vis(V, false);
        vector<bool> dfsVis(V, false);
        for(int i=0;i<V;i++){
            if (!vis[i]) {
                if (dfs(i,adj, vis,dfsVis)) 
                    return true; 
            }
        }
        return false;
    }
};
