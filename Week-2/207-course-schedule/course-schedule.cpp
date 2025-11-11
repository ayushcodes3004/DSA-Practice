class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto e: prerequisites){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
        }
        int V=adj.size();
        vector<int>indegree(V,0);
        for(int u=0;u<V;u++){
            for(int v:adj[u]){
                indegree[v]++;
            }
        }

        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0)  q.push(i);
        }
        int cnt=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            cnt++;
            for(auto neigh: adj[node]){
                indegree[neigh]--;
                if(indegree[neigh]==0)  q.push(neigh);
            }
        }

        return (cnt==V);
    }
};