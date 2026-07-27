class Solution {
public:

    vector<int> dx = {-1,0,1,0};
    vector<int> dy = {0,1,0,-1};

    void dfs(int i,int j,vector<vector<int>>&h,vector<vector<int>>&vis){

        vis[i][j]=1;

        for(int k=0;k<4;k++){

            int nx=i+dx[k];
            int ny=j+dy[k];

            if(nx>=0 && ny>=0 && nx<h.size() && ny<h[0].size()
               && !vis[nx][ny]
               && h[nx][ny] >= h[i][j]){

                dfs(nx,ny,h,vis);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int n=heights.size();
        int m=heights[0].size();

        vector<vector<int>> pac(n,vector<int>(m,0));
        vector<vector<int>> atl(n,vector<int>(m,0));

        // Pacific
        for(int i=0;i<n;i++)
            dfs(i,0,heights,pac);

        for(int j=0;j<m;j++)
            dfs(0,j,heights,pac);

        // Atlantic
        for(int i=0;i<n;i++)
            dfs(i,m-1,heights,atl);

        for(int j=0;j<m;j++)
            dfs(n-1,j,heights,atl);

        vector<vector<int>> ans;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pac[i][j] && atl[i][j])
                    ans.push_back({i,j});
            }
        }

        return ans;
    }
};