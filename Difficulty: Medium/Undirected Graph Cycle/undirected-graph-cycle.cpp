class Solution {
  private:
    bool bfs(int i,vector<vector<int>> &adj,vector<bool>& vis){
        queue<pair<int,int>> q;
        q.push({i, -1});
        vis[i] = true;

        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto neigh : adj[node]) {
                if (!vis[neigh]) {
                    vis[neigh] = true;
                    q.push({neigh, node});
                } 
                // If visited and not parent => cycle
                else if (neigh != parent) {
                    return true;
                }
            }
        }
        return false;
    }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(V, false);
        for(int i=0;i<V;i++){
            if (!vis[i]) {
                if (bfs(i, adj, vis)) 
                    return true; 
            }
        }
        return false;
    }
};