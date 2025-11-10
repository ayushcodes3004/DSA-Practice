class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=true;
                }
            }
        }
        int timer=0;
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            timer=max(timer,t);
            q.pop();
            int delr[]={-1,0,1,0};
            int delc[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int newr=r+delr[i];
                int newc=c+delc[i];
                if(newr>=0 && newr<m && newc>=0 && newc<n && !vis[newr][newc] && grid[newr][newc]==1){
                    q.push({{newr,newc},t+1});
                    grid[newr][newc]=2;
                    vis[newr][newc]=true;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)   return -1;
            }
        } 
        return timer;
    }
};