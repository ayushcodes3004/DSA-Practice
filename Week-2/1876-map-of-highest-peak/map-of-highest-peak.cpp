class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size();
        int n=isWater[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j]==1){
                    q.push({i,j});
                    isWater[i][j] = 0;  // water height = 0
                }else{
                    isWater[i][j]=-1;
                }
            }
        }
        vector<pair<int, int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(auto [dr,dc]:dirs){
                int nr=r+dr;
                int nc=c+dc;

                if(nr>=0 && nr<m && nc>=0 && nc<n && isWater[nr][nc]==-1){
                    isWater[nr][nc] = isWater[r][c] + 1; // height = neighbor + 1
                    q.push({nr,nc});
                }
            }
        }
        return isWater;
    }
};