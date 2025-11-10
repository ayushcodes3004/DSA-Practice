class Solution {
private:
    void dfs(int node, vector<vector<int>>& adjList, vector<bool>&visited ){
        visited[node]=1;
        for(int neighbour : adjList[node]){
            if(!visited[neighbour]) dfs(neighbour,adjList,visited);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && isConnected[i][j]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool>vis(n,false);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                cnt++;
            } 
        }
        return cnt;
    }
};