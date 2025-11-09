class Solution {
  private:
    void rec(int r, int c,string s,int n,vector<string>&ans,vector<vector<int>>& arr,vector<vector<int>>& vis){
        if(r<0 || c<0 || r>=n|| c>=n || arr[r][c]==0 || vis[r][c]==1)    return;
        if(r==n-1 && c==n-1){
            ans.push_back(s);
            return ;
        }
        vis[r][c]=1;
        rec(r-1,c,s+"U",n,ans,arr,vis);
        rec(r+1,c,s+"D",n,ans,arr,vis);
        rec(r,c-1,s+"L",n,ans,arr,vis);
        rec(r,c+1,s+"R",n,ans,arr,vis);
        
        vis[r][c]=0;
        
    }
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        int n=maze.size();
        vector<string>ans;
        if(maze[0][0]==0 || maze[n-1][n-1]==0)    return ans;
        vector<vector<int>>vis(n,vector<int>(n,0));
        string s="";
        rec(0,0,s,n,ans,maze,vis);
        sort(ans.begin(),ans.end());
        return ans;
    }
};