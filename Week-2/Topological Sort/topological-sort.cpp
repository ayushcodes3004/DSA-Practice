class Solution {
  private:
    void dfsHelper(int node,vector<vector<int>>& adj,vector<bool>& vis,stack<int>& s){
        vis[node]=true;
        for(int neigh: adj[node]){
            if(!vis[neigh]){
                // vis[neigh]=true;
                dfsHelper(neigh,adj,vis,s);
            }
        }
        s.push(node);
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        int n=edges.size();
        vector<vector<int>> adj(V);
        for(int i=0;i<n;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
        }
        vector<int>ans;
        vector<bool>vis(V,false);
        stack<int>s;
        for(int i=0;i<V;i++){
            if(!vis[i]) 
                dfsHelper(i,adj,vis,s);
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};