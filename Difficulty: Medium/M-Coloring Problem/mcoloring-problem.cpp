class Solution {
  private:
    bool isSafe(int i,int node,vector<vector<int>>&adj,vector<int>&color){
        for(int neigh: adj[node]){
            if(color[neigh]==i) return false;
        }
        return true;
    }
    bool rec(int node,int v,int m,vector<vector<int>>&adj,vector<int>&color){
        if(node==v) return true;
        for(int i=1;i<=m;i++){
            if(isSafe(i,node,adj,color)){
                color[node]=i;
                if(rec(node+1,v,m,adj,color))   return true;
                color[node]=0;
            }
        }
        return false;
    }
  public:
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // code here
        vector<vector<int>>adj(v);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int>color(v,0);
        return rec(0,v,m,adj,color);
    }
};