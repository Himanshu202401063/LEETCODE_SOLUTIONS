  class dsu{
      
       public:
       vector<int>size,parent;
           dsu(int n){
            parent.resize(n);
               size.resize(n,1);
                for(int i=0;i<n;i++){
                      parent[i]=i;
                }
           }

            int find (int n){
                 if(n== parent[n]) return n;
                 return parent[n] = find(parent[n]);
            }


             void us(int u,int v){
                      int up = find(u);
                      int vp = find(v);
                       if(up==vp) return;

                        if(size[up] > size[vp]){
                              size[up]+= size[vp];
                               parent[vp] =up;
                        }
                        else {
                            size[vp]+= size[up];
                             parent[up] =vp;
                        }

             }
  };


class Solution {
public:


 bool ok(int i,int j,int n,vector<vector<int>>&g){
      return (i>=0 && j>=0 && i<n && j<n && g[i][j]==1);
 }
    int largestIsland(vector<vector<int>>& grid) {
 int n = grid.size();
  int ans =0;
         dsu ds(n*n );
queue<pair<int,int>>q;
         vector<int>x={-1,0,1,0};
           vector<int> y={0,1,0,-1};
         for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                    continue;
                }
               int hc = i*n + j;

                 for(int  k=0;k<4;k++){
                     int nx = x[k]+i;
                     int ny = y[k] + j;


                      int hv =  nx*n + ny;
                     if (ok(nx,ny,n,grid)){
                           ds.us(hc,hv);
                     }
                 }
            }
         }


          while(!q.empty()){
              int u = q.front().first;
              int v = q.front().second;
              q.pop();
       int h= u*n + v;
                  
    set<int>s;
     int sum=1;
                   for(int i=0;i<4;i++){
                    int nx = x[i]+u;
                    int ny = y[i]+v;


                     
                      if(ok(nx,ny,n,grid)){
                              s.insert(ds.find(nx*n + ny));
                      }
                   }

                    for(auto&i:s){
                         sum+= ds.size[i];
                    }
                     ans = max(ans,sum);
          }
    for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(grid[i][j])
            ans=max(ans,ds.size[ds.find(i*n+j)]);
    }
}
       return ans;

        
    }
};