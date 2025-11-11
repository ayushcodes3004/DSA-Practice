class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(V);
        for(auto e: edges){
            int u=e[0];
            int v=e[1];
            int w=e[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0}); //{wt,node}}
        vector<bool>vis(V,false);
        // vis[0]=1;
        int sum=0;
        
        while(!pq.empty()){
            auto [wt, node] = pq.top();
            pq.pop();
            
            if(vis[node])    continue;
            
            vis[node]=true;
            sum+=wt;
            for(auto& [adjNode, adjWt]: adj[node]){
                if(!vis[adjNode]){
                    pq.push({adjWt,adjNode});
                }
            }
        }
        return sum;
        
    }
};
