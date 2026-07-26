

class dsu{
    public:
    vector<int>parent,size;
    dsu(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
   int find(int u){
    if(u==parent[u]) return u;
     return parent[u]= find(parent[u]);
   }

   void join(int u,int v){
    int up = find(u);
    int vp = find(v);
    if(vp==up) return;
    if(size[up] > size[vp]){
        size[up]+= size[vp];
        parent[vp]=up;
        
    }
    else {
        size[vp]+=size[up];
        parent[up] =vp;
    }
   }
};

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
          int n = grid.size();
          int m = grid[0].size();
          dsu ds(n*m +1);
          queue<pair<int,int>>q;
           vector<vector<int>>vis(n,vector<int>(m,0));
          for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) q.push({i,j});
            }
          }
         vector<int>x={-1,0,1,0};
         vector<int>y={0,1,0,-1};
          while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if(vis[i][j]) continue;
            vis[i][j]=1;
            
                 for(int  l =0;l<4;l++){
                    int nx = i+x[l];
                    int ny = j+y[l];
                    if(nx>=0 && ny>=0 && nx< n && ny< m && grid[nx][ny]==1 && !vis[nx][ny]){
                       

                        int a = m*(i) +j;
                        int b = m*(nx)+ ny;
                     ds.join(a,b);
                     q.push({nx,ny});

                    }
                 }
          }
int ans =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                 int a = i*m +j;
                 if(grid[i][j]) ans = max(ans,ds.size[ds.find(a)]);
            }
        }
         return ans;

    }
};