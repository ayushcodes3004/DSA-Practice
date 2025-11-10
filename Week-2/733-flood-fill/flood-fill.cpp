class Solution {
private:
    void dfs(int row,int col,vector<vector<int>>& image,vector<vector<int>>&ans, int initial, int final ){
        ans[row][col]=final;
        int m=image.size();
        int n=image[0].size();
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if((nrow>=0 && nrow<m) && (ncol>=0 && ncol<n) && (image[nrow][ncol]==initial) && (ans[nrow][ncol]!=final))
                dfs(nrow,ncol,image,ans,initial,final);
        }

    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans=image;
        int initial=image[sr][sc];
        ans[sr][sc]=color;
        dfs(sr,sc,image,ans,initial,color);
        return ans;
    }
};