class Solution {
public:
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
         return parent[u] = find(parent[u]);
    }

    void join(int u,int v){
         int up = find(u);
         int vp = find(v);
         if(up==vp) return;
         if(size[up] > size[vp]){
            size[up]+=size[vp];
            parent[vp]= up;
         }
         else {
            size[vp]+=size[up];
            parent[up]=vp;
         }
        
    }

};
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        dsu ds(edges.size());
        for(auto&i:edges){
            int u = i[0]-1;
            int v = i[1]-1;
            if(ds.find(u)==ds.find(v)) return {u+1,v+1};
            ds.join(u,v);
        }
         return {};
    }
};