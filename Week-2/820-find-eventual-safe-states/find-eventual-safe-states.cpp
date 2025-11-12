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
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<bool>vis(V,0);
        vector<bool>dfsVis(V,0);

        for(int i=0;i<V;i++){
            if(!vis[i]) dfs(i,graph,vis,dfsVis);
        }
        vector<int>ans;
        for(int i=0;i<V;i++){
            if(!dfsVis[i])  ans.push_back(i);
        }
        return ans;
    }
};