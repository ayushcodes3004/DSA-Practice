class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        // code here
        vector<int>dist(V,1e9);
        vector<vector<int>>adj(V);
        for(auto e: edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        queue<int>q;
        dist[src]=0;
        q.push(src);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto neigh: adj[node]){
                if(dist[node]+1<dist[neigh]){
                    dist[neigh]=1+dist[node];
                    q.push(neigh);
                }
            }
        }
        for(int i=0;i<V;i++)    if(dist[i]==(int)1e9)   dist[i]=-1;
        return dist;
    }
};