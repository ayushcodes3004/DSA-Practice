class Solution {
private:
    void bfs(int row,int col,vector<vector<char>>& grid,vector<vector<bool>>&vis){
        int m=grid.size();
        int n=grid[0].size();
        vis[row][col]=true;
        queue<pair<int,int>>q;
        q.push({row,col});
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nr=r+delrow[i];
                int nc=c+delcol[i];

                if(nr>=0 && nr<m && nc>=0 && nc<n && (!vis[nr][nc]) && (grid[nr][nc]=='1')){
                    q.push({nr,nc});
                    vis[nr][nc]=1;
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,0));
        int cnt=0;
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(!visited[row][col] && grid[row][col]=='1'){
                    cnt++;
                    bfs(row,col,grid,visited);
                }
            }
        }
        return cnt;
    }
};