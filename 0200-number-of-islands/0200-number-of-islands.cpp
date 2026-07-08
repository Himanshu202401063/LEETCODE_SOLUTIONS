class Solution {
public:
bool valid(int i,int j,int m,int n,vector<vector<char>>&grid){
     return (i>=0 && i<m && j>=0 && j< n && grid[i][j]=='1');
}
 vector<int>x={-1,0,1,0};
 vector<int>y={0,1,0,-1};
void dfs(vector<vector<int>>&vis,int i,int j,vector<vector<char>>&grid){
     int m = grid.size();
     int n =grid[0].size();
     if(!valid(i,j,m,n,grid)) return;
   vis[i][j]=1;
     for(int  l =0;l<4;l++){
        int nx = x[l]+i;
        int ny = y[l]+j;
       if(valid(nx,ny,m,n,grid) && !vis[nx][ny])
    dfs(vis,nx,ny,grid);
     }
}
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n =grid[0].size();
     vector<vector<int>>vis(m,vector<int>(n,0));
     int ans =0;
     for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if( grid[i][j]=='1' && !vis[i][j]){
                ans++;
                dfs(vis,i,j,grid);
            }
        }
     }
        return ans;  
    }
};