//Position this line where user code will be pasted.
class Solution {
  private:
    void dfs(int node,vector<bool>& vis,vector<vector<int>> &adj,stack<int>& st){
        vis[node]=true;
        for(int neigh: adj[node]){
            if(!vis[neigh]) dfs(neigh,vis,adj,st);
        }
        st.push(node);
    }
    void dfs(int node,vector<bool>& vis,vector<vector<int>> &adj){
        vis[node]=true;
        for(int neigh: adj[node]){
            if(!vis[neigh]) dfs(neigh,vis,adj);
        }
    }
  public:
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        //s1: sort all edge by finishing time
        int V=adj.size();
        vector<bool> vis(V,false);
        stack<int>st;
        for(int i=0;i<V;i++){
            if(!vis[i]) dfs(i,vis,adj,st);
        }
        
        //s2: reverse the graph
        vector<vector<int>> adjT(V);
        for(int u=0;u<V;u++){
            for(auto v: adj[u]){
                adjT[v].push_back(u);
            }
        }
        
        fill(vis.begin(),vis.end(),false);
        
        //s3: do dfs again to find scc
        int scc=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(!vis[node]){
                scc++;
                dfs(node,vis,adjT);
            }
        }
        return scc;
    }
};