// User function Template for C++
class DSU{
    vector<int>parent,rank;
  public:
    DSU(int n){
        parent.resize(n);
        rank.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int find(int i){
        return (parent[i]==i)?i:parent[i]=find(parent[i]);
    }
    void unite(int x,int y){
        int s1=find(x),s2=find(y);
        if(s1!=s2){
            if(rank[s1]<rank[s2])   parent[s1]=s2;
            else if(rank[s1]>rank[s2])  parent[s2]=s1;
            else{
                parent[s2]=s1;
                rank[s1]++;
            }    
            
        }
    }
};
bool cmpByWt(vector<int> &a,vector<int> &b){
    return a[2]<b[2];
}
class Solution {
  public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        sort(edges.begin(),edges.end(),cmpByWt);
        
        DSU dsu(V);
        int cost=0;
        
        for(auto e:edges){
            int x=e[0],y=e[1],w=e[2];
            
            //Make sure no cycle
            if(dsu.find(x)!=dsu.find(y)){
                dsu.unite(x,y);
                cost+=w;
            }
        }
        return cost;
    }
};