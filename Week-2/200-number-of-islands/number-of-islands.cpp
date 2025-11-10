class Solution {
private:
    void dfs(int row,int col,int cnt,vector<vector<char>>& grid,vector<vector<bool>>&vis){
        vis[row][col]=true;
        int m=grid.size();
        int n=grid[0].size();
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if((nrow>=0 && nrow<m) && (ncol>=0 && ncol<n) && (grid[nrow][ncol]=='1') && (!vis[nrow][ncol]))
                dfs(nrow,ncol,cnt,grid,vis);
        }

    }
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size(),false));
        int cnt=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    dfs(i,j,cnt,grid,vis);
                    cnt++;
                }
                
            }
        }
        return cnt;
    }
};