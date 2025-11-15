// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<int>dist(V,1e9);
        vector<vector<pair<int,int>>>adj(V);
        for(auto e: edges){
            int u=e[0];
            int v=e[1];
            int wt=e[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        dist[src]=0;
        pq.push({0,src});
        
        while(!pq.empty()){
            int currDist=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto [neigh,wt]: adj[node]){
                if(dist[node]+wt<dist[neigh]){
                    dist[neigh]=wt+dist[node];
                    pq.push({dist[neigh],neigh});
                }
            }
        }
        return dist;
    }
};